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

struct CpuTimes
{
    unsigned long long user = 0, nice = 0, system = 0, idle = 0, iowait = 0, irq = 0, softirq = 0, steal = 0;
};
struct MemInfo
{
    long memTotal = 0, memFree = 0, MemAvailable = 0, Buffers = 0, Cached = 0, swapTotal = 0, swapFree = 0;
};
struct NetStats
{
    uint64_t rx = 0, tx = 0;
};
struct DiskUsage
{
    unsigned long long total = 0, free = 0;
};

vector<CpuTimes> readAllCpuTimes()
{
    ifstream f("/proc/stat");
    vector<CpuTimes> times;
    string line;
    while (getline(f, line))
    {
        if (line.rfind("cpu", 0) == 0)
        {
            istringstream iss(line);
            string label;
            CpuTimes t;
            iss >> label >> t.user >> t.nice >> t.system >> t.idle >> t.iowait >> t.irq >> t.softirq >> t.steal;
            times.push_back(t);
        }
        else
            break;
    }
    return times;
}

double calcCpuUsage(const CpuTimes &prev, const CpuTimes &now)
{
    unsigned long long prevIdle = prev.idle + prev.iowait;
    unsigned long long idle = now.idle + now.iowait;
    unsigned long long prevNonIdle = prev.user + prev.nice + prev.system +
                                     prev.irq + prev.softirq + prev.steal;
    unsigned long long nonIdle = now.user + now.nice + now.system +
                                 now.irq + now.softirq + now.steal;
    unsigned long long prevTotal = prevIdle + prevNonIdle;
    unsigned long long total = idle + nonIdle;
    unsigned long long totald = total - prevTotal;
    unsigned long long idled = idle - prevIdle;
    return totald > 0 ? (totald - idled) * 100.0 / totald : 0.0;
}

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

double readUptime()
{
    ifstream f("/proc/uptime");
    double up = 0, idle = 0;
    f >> up >> idle;
    return up;
}

vector<string> listInterfaces()
{
    ifstream file("/proc/net/dev");
    string line;
    vector<string> ifaces;
    while (getline(file, line))
    {
        auto pos = line.find(':');
        if (pos != string::npos)
        {
            string iface = line.substr(0, pos);
            iface.erase(0, iface.find_first_not_of(" \t"));
            iface.erase(iface.find_last_not_of(" \t") + 1);
            ifaces.push_back(iface);
        }
    }
    return ifaces;
}

NetStats readNet(const string &iface)
{
    ifstream file("/proc/net/dev");
    string line;
    while (getline(file, line))
    {
        if (line.find(iface + ":") != string::npos)
        {
            replace(line.begin(), line.end(), ':', ' ');
            istringstream iss(line);
            string name;
            NetStats ns;
            iss >> name >> ns.rx;
            for (int i = 0; i < 7; i++)
            {
                uint64_t tmp;
                iss >> tmp;
            }
            iss >> ns.tx;
            return ns;
        }
    }
    return {};
}

void getTerminalSize(int &rows, int &cols)
{
    struct winsize w{};
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    rows = w.ws_row;
    cols = w.ws_col;
}

void printBlockCentered(const vector<string> &lines)
{
    int rows, cols;
    getTerminalSize(rows, cols);
    size_t maxw = 0;
    for (auto &l : lines)
        maxw = max(maxw, l.size());
    int padTop = max(0, (rows - (int)lines.size()) / 2);
    for (int i = 0; i < padTop; ++i)
        cout << "\n";
    int padLeft = max(0, (cols - (int)maxw) / 2);
    for (auto &line : lines)
        cout << string(padLeft, ' ') << line << "\n";
}

// Get IPv4 address of an interface
string getIpAddress(const string &iface)
{
    struct ifaddrs *ifaddr, *ifa;
    string ip = "N/A";
    if (getifaddrs(&ifaddr) == -1)
    {
        return ip;
    }
    for (ifa = ifaddr; ifa != nullptr; ifa = ifa->ifa_next)
    {
        if (ifa->ifa_addr == nullptr)
            continue;
        if (iface == ifa->ifa_name && ifa->ifa_addr->sa_family == AF_INET)
        {
            char addr[INET_ADDRSTRLEN];
            void *in_addr = &((struct sockaddr_in *)ifa->ifa_addr)->sin_addr;
            if (inet_ntop(AF_INET, in_addr, addr, sizeof(addr)))
            {
                ip = addr;
                break;
            }
        }
    }
    freeifaddrs(ifaddr);
    return ip;
}

// Disk usage of root (or given path)
DiskUsage getDiskUsage(const string &path = "/")
{
    struct statvfs stat{};
    DiskUsage du;
    if (statvfs(path.c_str(), &stat) == 0)
    {
        du.total = stat.f_blocks * stat.f_frsize;
        du.free = stat.f_bavail * stat.f_frsize;
    }
    return du;
}

int main()
{
    auto ifaces = listInterfaces();
    if (ifaces.empty())
    {
        cerr << "No interfaces found.\n";
        return 1;
    }

    cout << "Available interfaces:\n";
    for (size_t i = 0; i < ifaces.size(); ++i)
        cout << i << ": " << ifaces[i] << "\n";
    cout << "Select interface index: ";
    int choice;
    cin >> choice;
    if (choice < 0 || choice >= (int)ifaces.size())
        return 1;
    string iface = ifaces[choice];
    string ip = getIpAddress(iface);

    cout << "\033[?1049h"; // alternate screen

    vector<CpuTimes> prevCpuAll = readAllCpuTimes();
    NetStats prevNet = readNet(iface);

    const int labelWidth = 12;

    while (true)
    {
        this_thread::sleep_for(1s);

        vector<CpuTimes> nowCpuAll = readAllCpuTimes();
        double totalCpuUsage = calcCpuUsage(prevCpuAll[0], nowCpuAll[0]);

        auto toGB = [](double kb)
        { return kb / 1048576.0; };

        MemInfo mi = readMemInfo();
        double memUsed = mi.memTotal - mi.memFree - mi.Buffers - mi.Cached;
        double memPercent = memUsed * 100.0 / mi.memTotal;
        double swapUsed = mi.swapTotal - mi.swapFree;
        double swapPercent = (mi.swapTotal > 0) ? swapUsed * 100.0 / mi.swapTotal : 0.0;

        double uptime = readUptime();
        int totalSeconds = static_cast<int>(uptime);

        // --- UPDATED UPTIME CALCULATION (htop-style) ---
        int days = totalSeconds / (24 * 3600);
        int hours = (totalSeconds % (24 * 3600)) / 3600;
        int minutes = (totalSeconds % 3600) / 60;
        int seconds = totalSeconds % 60;
        // ------------------------------------------------

        NetStats nowNet = readNet(iface);
        double rxBps = (nowNet.rx - prevNet.rx);
        double txBps = (nowNet.tx - prevNet.tx);
        prevNet = nowNet;

        DiskUsage du = getDiskUsage("/");
        double diskUsed = du.total - du.free;
        double diskPercent = du.total > 0 ? (diskUsed * 100.0 / du.total) : 0.0;

        vector<string> lines;
        lines.push_back("System Monitor");
        lines.push_back("-----------------------------");

        ostringstream oss;
        oss << left << setw(labelWidth) << "Uptime:" << right;
        if (days > 0)
        {
            oss << days << "d "
                << setfill('0') << setw(2) << hours << ":"
                << setw(2) << minutes << ":" << setw(2) << seconds;
        }
        else
        {
            oss << setfill('0') << setw(2) << hours << ":"
                << setw(2) << minutes << ":" << setw(2) << seconds;
        }
        lines.push_back(oss.str());
        oss.str("");
        oss.clear();

        oss << setfill(' ') << left << setw(labelWidth) << "CPU Usage:"
            << fixed << setprecision(2) << totalCpuUsage << " %";
        lines.push_back(oss.str());
        oss.str("");
        oss.clear();

        // ---------- CPU CORES TABLE ----------
        size_t logical = nowCpuAll.size() - 1;
        size_t cores = logical / 2 + logical % 2;
        lines.push_back("Cores Usage:");
        {
            string header = "+--------+--------+";
            lines.push_back(header);
            for (size_t c = 0; c < cores; c++)
            {
                size_t t1 = 1 + 2 * c;
                size_t t2 = t1 + 1;
                double u1 = calcCpuUsage(prevCpuAll[t1], nowCpuAll[t1]);
                double u2 = (t2 < nowCpuAll.size())
                                ? calcCpuUsage(prevCpuAll[t2], nowCpuAll[t2])
                                : u1;
                double avg = (u1 + u2) / ((t2 < nowCpuAll.size()) ? 2.0 : 1.0);
                ostringstream line;
                line << "|" << setw(6) << left << ("C" + to_string(c))
                     << "|" << setw(6) << right << fixed << setprecision(1) << avg << "%|";
                lines.push_back(line.str());
            }
            lines.push_back(header);
        }

        // ---------- CPU THREADS TABLE ----------
        lines.push_back("Threads Usage:");
        {
            vector<string> row;
            size_t colWidth = 15;
            for (size_t i = 1; i < nowCpuAll.size(); ++i)
            {
                double u = calcCpuUsage(prevCpuAll[i], nowCpuAll[i]);
                ostringstream cell;
                cell << "T" << setw(2) << setfill('0') << (i - 1) << ": "
                     << fixed << setprecision(1) << u << "%";
                row.push_back(cell.str());
            }
            prevCpuAll = nowCpuAll;

            for (size_t i = 0; i < row.size(); i += 4)
            {
                ostringstream line;
                for (size_t j = i; j < i + 4 && j < row.size(); ++j)
                    line << left << setw(colWidth) << setfill(' ') << row[j];
                lines.push_back(line.str());
            }
        }

        // Memory, Swap, Net
        {
            ostringstream mem;
            mem << fixed << setprecision(1) << toGB(memUsed) << " GB / " << toGB(mi.memTotal) << " GB ("
                << fixed << setprecision(2) << memPercent << "%)";
            oss << left << setw(labelWidth) << "Memory:" << mem.str();
            lines.push_back(oss.str());
            oss.str("");
            oss.clear();
        }
        {
            ostringstream sw;
            sw << (swapUsed / 1024) << " MB / " << (mi.swapTotal / 1024) << " MB ("
               << fixed << setprecision(2) << swapPercent << "%)";
            oss << left << setw(labelWidth) << "Swap:" << sw.str();
            lines.push_back(oss.str());
            oss.str("");
            oss.clear();
        }
        oss << left << setw(labelWidth) << "Interface:" << iface;
        lines.push_back(oss.str());
        oss.str("");
        oss.clear();

        // Show IP
        oss << left << setw(labelWidth) << "IP Addr:" << ip;
        lines.push_back(oss.str());
        oss.str("");
        oss.clear();

        // Disk usage
        {
            ostringstream ds;
            ds << fixed << setprecision(2)
               << (du.free / (1024.0 * 1024 * 1024)) << " GB / "
               << (du.total / (1024.0 * 1024 * 1024)) << " GB ("
               << diskPercent << "% used)";
            oss << left << setw(labelWidth) << "Disk(/):" << ds.str();
            lines.push_back(oss.str());
            oss.str("");
            oss.clear();
        }

        {
            ostringstream net;
            net << (rxBps / 1024) << " KB/s / " << (txBps / 1024) << " KB/s";
            oss << left << setw(labelWidth) << "RX/TX:" << net.str();
            lines.push_back(oss.str());
        }

        cout << "\033[H\033[J";
        printBlockCentered(lines);
        cout.flush();
    }

    cout << "\033[?1049l";
}
