#include <iostream>
#include <string>
#include <array>
#include <cstdio>
#include <thread>
#include <chrono>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <unistd.h>
#include <signal.h>

// Run shell command
std::string execCmd(const std::string &cmd)
{
    std::array<char, 256> buffer{};
    std::string result;
    FILE *pipe = popen(cmd.c_str(), "r");
    if (!pipe)
        return "";
    while (fgets(buffer.data(), buffer.size(), pipe))
    {
        result += buffer.data();
    }
    pclose(pipe);
    result.erase(std::remove(result.begin(), result.end(), '\n'), result.end());
    return result;
}

// Detect media using playerctl
bool isMediaPlaying()
{
    std::string players = execCmd("playerctl -l 2>/dev/null");
    std::istringstream iss(players);
    std::string p;
    while (iss >> p)
    {
        std::string status = execCmd("playerctl --player=" + p + " status 2>/dev/null");
        if (status == "Playing")
        {
            std::cout << "[INFO] Video/audio playing in: " << p << "\n";
            return true;
        }
    }
    return false;
}

// CPU usage calculation
struct CpuTimes
{
    unsigned long long user = 0, nice = 0, system = 0, idle = 0, iowait = 0, irq = 0, softirq = 0, steal = 0;
};

CpuTimes readCpu()
{
    std::ifstream f("/proc/stat");
    CpuTimes t;
    std::string line;
    if (std::getline(f, line))
    {
        std::istringstream iss(line);
        std::string label;
        iss >> label >> t.user >> t.nice >> t.system >> t.idle >> t.iowait >> t.irq >> t.softirq >> t.steal;
    }
    return t;
}

double cpuUsage(const CpuTimes &prev, const CpuTimes &now)
{
    auto idle = now.idle + now.iowait;
    auto prevIdle = prev.idle + prev.iowait;
    auto nonIdle = now.user + now.nice + now.system + now.irq + now.softirq + now.steal;
    auto prevNonIdle = prev.user + prev.nice + prev.system + prev.irq + prev.softirq + prev.steal;
    auto total = idle + nonIdle;
    auto prevTotal = prevIdle + prevNonIdle;
    auto totald = total - prevTotal;
    auto idled = idle - prevIdle;
    return totald > 0 ? (totald - idled) * 100.0 / totald : 0.0;
}
//----------------------------------------------------------

pid_t inhibitor_pid = -1;

void inhibit()
{
    if (inhibitor_pid > 0)
        return; // already running
    inhibitor_pid = fork();
    if (inhibitor_pid == 0)
    {
        execlp("systemd-inhibit", "systemd-inhibit",
               "--what=handle-lid-switch:sleep",
               "--who=caffeine-cli",
               "--why=Preventing sleep",
               "sleep", "infinity",
               (char *)nullptr);
        _exit(1);
    }
    std::cout << "[ACTION] >>> Started systemd-inhibit\n";
}

void uninhibit()
{
    if (inhibitor_pid > 0)
    {
        kill(inhibitor_pid, SIGTERM);
        inhibitor_pid = -1;
        std::cout << "[ACTION] <<< Stopped systemd-inhibit\n";
    }
}

//-----------------------------------------------------------
// DBus inhibition
// unsigned inhibit_cookie = 0;
// void inhibit() {
//     if (inhibit_cookie) return;
//     std::string cmd =
//         "dbus-send --session --print-reply --dest=org.xfce.PowerManager "
//         "/org/xfce/PowerManager org.xfce.PowerManager.Inhibit "
//         "string:'caffeine-cli' string:'Prevent sleep'";
//     std::string out = execCmd(cmd);
//     auto pos = out.find_last_of(' ');
//     if (pos != std::string::npos) inhibit_cookie = std::stoul(out.substr(pos+1));
//     std::cout << "[ACTION] >>> Inhibiting suspend\n";
// }
// void uninhibit() {
//     if (!inhibit_cookie) return;
//     std::string cmd =
//         "dbus-send --session --dest=org.xfce.PowerManager "
//         "/org/xfce/PowerManager org.xfce.PowerManager.UnInhibit uint32:" + std::to_string(inhibit_cookie);
//     system(cmd.c_str());
//     std::cout << "[ACTION] <<< Allowing suspend\n";
//     inhibit_cookie = 0;
// }
//------------------------------------------------------
// unsigned inhibit_cookie = 0;

// void inhibit()
// {
//     if (inhibit_cookie)
//         return;
//     std::string cmd =
//         "dbus-send --session --print-reply "
//         "--dest=org.freedesktop.ScreenSaver "
//         "/ScreenSaver org.freedesktop.ScreenSaver.Inhibit "
//         "string:'caffeine-cli' string:'Prevent sleep'";
//     std::string out = execCmd(cmd);
//     // Extract cookie (last number in output)
//     auto pos = out.find_last_of(' ');
//     if (pos != std::string::npos)
//         inhibit_cookie = std::stoul(out.substr(pos + 1));
//     std::cout << "[ACTION] >>> Inhibiting suspend\n";
// }

// void uninhibit()
// {
//     if (!inhibit_cookie)
//         return;
//     std::string cmd =
//         "dbus-send --session "
//         "--dest=org.freedesktop.ScreenSaver "
//         "/ScreenSaver org.freedesktop.ScreenSaver.UnInhibit "
//         "uint32:" +
//         std::to_string(inhibit_cookie);
//     system(cmd.c_str());
//     std::cout << "[ACTION] <<< Allowing suspend\n";
//     inhibit_cookie = 0;
// }

//-----------------------------------------------------

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    CpuTimes prev = readCpu();
    bool last = false;
    int highCpuCount = 0;
    //const double cpuThreshold = 30.0;
    const double cpuThreshold = 20.0;
    const int sustain = 3;

    std::cout << "Caffeine-like monitor running...\n";
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(10));
        bool playing = isMediaPlaying();

        CpuTimes now = readCpu();
        double cpu = cpuUsage(prev, now);
        prev = now;
        //std::cout << "[DEBUG] CPU usage: " << cpu << "%\n";

        if (!playing)
        {
            if (cpu > cpuThreshold)
            {
                highCpuCount++;
                std::cout << "[DEBUG] High CPU (" << highCpuCount << "/" << sustain << ")\n";
                if (highCpuCount >= sustain)
                {
                    playing = true; // fallback
                    std::cout << "[INFO] Using CPU fallback to keep awake.\n";
                }
            }
            else
            {
                highCpuCount = 0;
            }
        }
        else
        {
            highCpuCount = 0;
        }

        if (playing && !last)
            inhibit();
        else if (!playing && last)
            uninhibit();
        last = playing;
    }
    return 0;
}
