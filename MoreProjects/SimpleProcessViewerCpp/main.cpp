/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief htop command using C++

 * @version 0.1
 * @date 2024-10-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <dirent.h>
#include <pwd.h>
#include <unistd.h>

// Structure to store process information
struct ProcessInfo
{
    int pid;
    std::string user;
    float cpuUsage;
    float memoryUsage;
};

// Check if a string is a number (to validate PIDs)
bool isNumber(const std::string &str)
{
    for (char c : str)
    {
        if (!isdigit(c))
            return false;
    }
    return true;
}

// Resolve UID to username
std::string getUserName(uid_t uid)
{
    struct passwd *pw = getpwuid(uid);
    return pw ? pw->pw_name : "Unknown";
}

// Get CPU usage percentage (calculated over a short delay)
float getCpuUsage(int pid)
{
    std::ifstream statFile("/proc/" + std::to_string(pid) + "/stat");
    if (!statFile)
        return 0.0;

    std::string line;
    std::getline(statFile, line);
    std::istringstream iss(line);

    // Extract fields from /proc/[pid]/stat
    std::string temp;
    long utime, stime, cutime, cstime, starttime;
    int field = 0;
    while (iss >> temp)
    {
        ++field;
        if (field == 14)
            utime = std::stol(temp); // User mode time
        if (field == 15)
            stime = std::stol(temp); // Kernel mode time
        if (field == 16)
            cutime = std::stol(temp); // Children's user time
        if (field == 17)
            cstime = std::stol(temp); // Children's kernel time
        if (field == 22)
            starttime = std::stol(temp); // Start time
    }

    long total_time = utime + stime + cutime + cstime;
    return (total_time / (float)sysconf(_SC_CLK_TCK)); // CPU seconds
}

// Get memory usage in MB
float getMemoryUsage(int pid)
{
    std::ifstream statusFile("/proc/" + std::to_string(pid) + "/status");
    if (!statusFile)
        return 0.0;

    std::string line;
    while (std::getline(statusFile, line))
    {
        if (line.find("VmRSS:") == 0)
        {
            std::istringstream iss(line);
            std::string label;
            float memory_kb;
            iss >> label >> memory_kb;
            return memory_kb / 1024.0; // Convert KB to MB
        }
    }
    return 0.0;
}

// Fetch process information
std::vector<ProcessInfo> getProcesses()
{
    std::vector<ProcessInfo> processes;
    DIR *procDir = opendir("/proc");
    if (!procDir)
        return processes;

    struct dirent *entry;
    while ((entry = readdir(procDir)) != nullptr)
    {
        if (entry->d_type == DT_DIR && isNumber(entry->d_name))
        {
            int pid = std::stoi(entry->d_name);
            std::ifstream statusFile("/proc/" + std::to_string(pid) + "/status");
            if (!statusFile)
                continue;

            // Parse UID and username
            std::string line, user = "Unknown";
            uid_t uid = -1;
            while (std::getline(statusFile, line))
            {
                if (line.find("Uid:") == 0)
                {
                    std::istringstream iss(line);
                    std::string label;
                    iss >> label >> uid;
                    user = getUserName(uid);
                    break;
                }
            }

            // Get memory and CPU usage
            float memoryUsage = getMemoryUsage(pid);
            float cpuUsage = getCpuUsage(pid);

            // Store process information
            processes.push_back({pid, user, cpuUsage, memoryUsage});
        }
    }

    closedir(procDir);
    return processes;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    // Fetch processes
    std::vector<ProcessInfo> processes = getProcesses();

    // Print header
    std::cout << "PID\tUSER\t\tCPU(s)\tMEM(MB)\n";
    std::cout << "-----------------------------------------\n";

    // Print top 10 processes
    int count = 0;

    // Print process information
    for (const auto &proc : processes)
    {
        std::cout << proc.pid << "\t" << proc.user << "\t\t"
                  << proc.cpuUsage << "\t" << proc.memoryUsage << "\n";

        if (++count >= 10)
            break; // Stop after top 10
    }

    return 0;
}
