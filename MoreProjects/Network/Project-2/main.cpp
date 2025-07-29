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

using namespace std;

struct CpuTimes {
    unsigned long long user=0,nice=0,system=0,idle=0,iowait=0,irq=0,softirq=0,steal=0;
};

CpuTimes readCpuTimes() {
    ifstream f("/proc/stat");
    string cpu;
    CpuTimes t;
    f >> cpu >> t.user >> t.nice >> t.system >> t.idle >> t.iowait >> t.irq >> t.softirq >> t.steal;
    return t;
}

double calculateCpuUsage(const CpuTimes &prev, const CpuTimes &now) {
    unsigned long long prevIdle = prev.idle + prev.iowait;
    unsigned long long idle = now.idle + now.iowait;

    unsigned long long prevNonIdle = prev.user + prev.nice + prev.system + prev.irq + prev.softirq + prev.steal;
    unsigned long long nonIdle = now.user + now.nice + now.system + now.irq + now.softirq + now.steal;

    unsigned long long prevTotal = prevIdle + prevNonIdle;
    unsigned long long total = idle + nonIdle;

    unsigned long long totald = total - prevTotal;
    unsigned long long idled = idle - prevIdle;

    return (totald - idled) * 100.0 / totald;
}

struct MemInfo {
    long memTotal=0, memFree=0, swapTotal=0, swapFree=0;
};

MemInfo readMemInfo() {
    MemInfo mi;
    ifstream f("/proc/meminfo");
    string key;
    long value;
    string unit;
    while (f >> key >> value >> unit) {
        if (key == "MemTotal:") mi.memTotal = value;
        else if (key == "MemFree:") mi.memFree = value;
        else if (key == "SwapTotal:") mi.swapTotal = value;
        else if (key == "SwapFree:") mi.swapFree = value;
    }
    return mi;
}

double readUptime() {
    ifstream f("/proc/uptime");
    double up=0, idle=0;
    f >> up >> idle;
    return up;
}

struct NetStats {
    uint64_t rx=0, tx=0;
};

vector<string> listInterfaces() {
    ifstream file("/proc/net/dev");
    string line;
    vector<string> ifaces;
    while (getline(file, line)) {
        auto pos = line.find(':');
        if (pos != string::npos) {
            string iface = line.substr(0, pos);
            iface.erase(0, iface.find_first_not_of(" \t"));
            iface.erase(iface.find_last_not_of(" \t")+1);
            ifaces.push_back(iface);
        }
    }
    return ifaces;
}

NetStats readNet(const string &iface) {
    ifstream file("/proc/net/dev");
    string line;
    while (getline(file, line)) {
        if (line.find(iface + ":") != string::npos) {
            replace(line.begin(), line.end(), ':', ' ');
            istringstream iss(line);
            string name;
            NetStats ns;
            iss >> name >> ns.rx;
            for (int i = 0; i < 7; i++) { uint64_t tmp; iss >> tmp; }
            iss >> ns.tx;
            return ns;
        }
    }
    return {};
}

int main() {
    // Choose network interface
    auto ifaces = listInterfaces();
    if (ifaces.empty()) {
        cerr << "No interfaces found.\n";
        return 1;
    }
    cout << "Available interfaces:\n";
    for (size_t i=0; i<ifaces.size(); ++i)
        cout << i << ": " << ifaces[i] << "\n";
    cout << "Select interface index: ";
    int choice;
    cin >> choice;
    if (choice < 0 || choice >= (int)ifaces.size()) return 1;
    string iface = ifaces[choice];

    // Enter alternate screen
    cout << "\033[?1049h";

    CpuTimes prevCpu = readCpuTimes();
    NetStats prevNet = readNet(iface);

    while (true) {
        this_thread::sleep_for(1s);

        CpuTimes nowCpu = readCpuTimes();
        double cpuUsage = calculateCpuUsage(prevCpu, nowCpu);
        prevCpu = nowCpu;

        MemInfo mi = readMemInfo();
        double memUsed = mi.memTotal - mi.memFree;
        double memPercent = memUsed * 100.0 / mi.memTotal;

        double swapUsed = mi.swapTotal - mi.swapFree;
        double swapPercent = (mi.swapTotal > 0) ? swapUsed * 100.0 / mi.swapTotal : 0.0;

        double uptime = readUptime();

        NetStats nowNet = readNet(iface);
        double rxBps = (nowNet.rx - prevNet.rx);
        double txBps = (nowNet.tx - prevNet.tx);
        prevNet = nowNet;

        // Clear screen and move to top-left
        cout << "\033[H";
        cout << fixed << setprecision(2);
        cout << "System Monitor (like top)\n";
        cout << "--------------------------\n";
        cout << "Uptime: " << uptime/3600 << "h\n";
        cout << "CPU Usage: " << cpuUsage << " %\n";
        cout << "Memory: " << memUsed/1024 << " MB / " << mi.memTotal/1024 << " MB (" << memPercent << "%)\n";
        cout << "Swap: " << swapUsed/1024 << " MB / " << mi.swapTotal/1024 << " MB (" << swapPercent << "%)\n";
        cout << "Interface: " << iface << "\n";
        cout << "RX: " << rxBps/1024 << " KB/s  TX: " << txBps/1024 << " KB/s\n";
        cout.flush();
    }

    // Exit alternate screen (never reached unless break)
    cout << "\033[?1049l";
}
