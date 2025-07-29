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

using namespace std;

struct CpuTimes { unsigned long long user=0,nice=0,system=0,idle=0,iowait=0,irq=0,softirq=0,steal=0; };
struct MemInfo { long memTotal=0, memFree=0, swapTotal=0, swapFree=0; };
struct NetStats { uint64_t rx=0, tx=0; };

CpuTimes readCpuTimes() {
    ifstream f("/proc/stat");
    string cpu; CpuTimes t;
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

MemInfo readMemInfo() {
    MemInfo mi;
    ifstream f("/proc/meminfo");
    string key; long value; string unit;
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

vector<string> listInterfaces() {
    ifstream file("/proc/net/dev");
    string line; vector<string> ifaces;
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
            string name; NetStats ns;
            iss >> name >> ns.rx;
            for (int i = 0; i < 7; i++) { uint64_t tmp; iss >> tmp; }
            iss >> ns.tx;
            return ns;
        }
    }
    return {};
}

// Get terminal size
void getTerminalSize(int &rows, int &cols) {
    struct winsize w{};
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    rows = w.ws_row;
    cols = w.ws_col;
}

// Center the whole block
void printBlockCentered(const vector<string> &lines) {
    int rows, cols;
    getTerminalSize(rows, cols);

    // compute max line width
    size_t maxw = 0;
    for (auto &l: lines) maxw = max(maxw, l.size());

    int padTop = max(0, (rows - (int)lines.size()) / 2);
    for (int i=0; i<padTop; ++i) cout << "\n";

    int padLeft = max(0, (cols - (int)maxw) / 2);
    for (auto &line : lines) {
        cout << string(padLeft, ' ') << line << "\n";
    }
}

int main() {
    auto ifaces = listInterfaces();
    if (ifaces.empty()) { cerr << "No interfaces found.\n"; return 1; }

    cout << "Available interfaces:\n";
    for (size_t i=0; i<ifaces.size(); ++i) cout << i << ": " << ifaces[i] << "\n";
    cout << "Select interface index: ";
    int choice; cin >> choice;
    if (choice < 0 || choice >= (int)ifaces.size()) return 1;
    string iface = ifaces[choice];

    cout << "\033[?1049h"; // alternate screen

    CpuTimes prevCpu = readCpuTimes();
    NetStats prevNet = readNet(iface);

    const int labelWidth = 12; // fixed width for labels

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
        int totalSeconds = static_cast<int>(uptime);
        int hours = totalSeconds / 3600;
        int minutes = (totalSeconds % 3600) / 60;
        int seconds = totalSeconds % 60;

        NetStats nowNet = readNet(iface);
        double rxBps = (nowNet.rx - prevNet.rx);
        double txBps = (nowNet.tx - prevNet.tx);
        prevNet = nowNet;

        // Build block with proper label/value columns
        vector<string> lines;
        lines.push_back("System Monitor");
        lines.push_back("-----------------------------");

        ostringstream oss;
        oss << left << setw(labelWidth) << "Uptime:" << right
            << setw(0) << setfill('0')
            << setw(2) << hours << ":"
            << setw(2) << minutes << ":"
            << setw(2) << seconds;
        lines.push_back(oss.str());
        oss.str(""); oss.clear();

        oss << left << setw(labelWidth) << setfill(' ') << "CPU Usage:" 
            << right << fixed << setprecision(2) << cpuUsage << " %";
        lines.push_back(oss.str());
        oss.str(""); oss.clear();

        {
            ostringstream mem;
            mem << (memUsed/1024) << " MB / " << (mi.memTotal/1024) << " MB (" 
                << fixed << setprecision(2) << memPercent << "%)";
            oss << left << setw(labelWidth) << "Memory:" << right << mem.str();
            lines.push_back(oss.str());
            oss.str(""); oss.clear();
        }

        {
            ostringstream sw;
            sw << (swapUsed/1024) << " MB / " << (mi.swapTotal/1024) << " MB (" 
               << fixed << setprecision(2) << swapPercent << "%)";
            oss << left << setw(labelWidth) << "Swap:" << right << sw.str();
            lines.push_back(oss.str());
            oss.str(""); oss.clear();
        }

        oss << left << setw(labelWidth) << "Interface:" << right << iface;
        lines.push_back(oss.str());
        oss.str(""); oss.clear();

        {
            ostringstream net;
            net << (rxBps/1024) << " KB/s / " << (txBps/1024) << " KB/s";
            oss << left << setw(labelWidth) << "RX/TX:" << right << net.str();
            lines.push_back(oss.str());
        }

        // Clear screen and print block centered
        cout << "\033[H\033[J";
        printBlockCentered(lines);
        cout.flush();
    }

    cout << "\033[?1049l";
}
