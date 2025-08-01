#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <thread>
#include <chrono>
#include <string>
#include <algorithm>
#include <iomanip>
#include <unistd.h>
#include <sys/ioctl.h>
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/statvfs.h>

using namespace std;

struct MemInfo
{
    long memTotal = 0, memFree = 0, MemAvailable = 0, Buffers = 0, Cached = 0, swapTotal = 0, swapFree = 0;
};

MemInfo readMemInfo()
{
    MemInfo mi;
    ifstream f("/proc/meminfo");
    string key;
    long value;
    string unit;
    while (f >> key >> value >> unit)
    {
        if (key == "MemTotal:")
            mi.memTotal = value;
        else if (key == "MemFree:")
            mi.memFree = value;
        else if (key == "MemAvailable:")
            mi.MemAvailable = value;
        else if (key == "Buffers:")
            mi.Buffers = value;
        else if (key == "Cached:")
            mi.Cached = value;
        else if (key == "SwapTotal:")
            mi.swapTotal = value;
        else if (key == "SwapFree:")
            mi.swapFree = value;
    }
    return mi;
}

int main()
{
    auto toGB = [](double kb)
    { return kb / 1048576.0; };

    MemInfo mi = readMemInfo();

    double memUsed = mi.memTotal - mi.memFree - mi.Buffers - mi.Cached;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Total:     " << toGB(mi.memTotal) << " GB\n";
    std::cout << "Free:      " << toGB(mi.memFree) << " GB\n";
    std::cout << "Available: " << toGB(mi.MemAvailable) << " GB\n";
    std::cout << "Occupied:  " << toGB(memUsed) << " GB\n";
}
