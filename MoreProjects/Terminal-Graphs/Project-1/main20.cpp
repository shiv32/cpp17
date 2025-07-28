#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <thread>
#include <chrono>
#include <algorithm>
#include <iomanip>
#include <string>
#include <unistd.h>

using namespace std;

const int WIDTH = 60;  // 60 samples (seconds)
const int HEIGHT = 10; // Graph height per graph

struct NetStats
{
    uint64_t rxBytes = 0;
    uint64_t txBytes = 0;
};

// Get list of interfaces from /proc/net/dev
vector<string> listInterfaces()
{
    ifstream file("/proc/net/dev");
    string line;
    vector<string> interfaces;
    while (getline(file, line))
    {
        auto pos = line.find(':');
        if (pos != string::npos)
        {
            string iface = line.substr(0, pos);
            // trim whitespace
            iface.erase(0, iface.find_first_not_of(" \t"));
            iface.erase(iface.find_last_not_of(" \t") + 1);
            interfaces.push_back(iface);
        }
    }
    return interfaces;
}

NetStats readNetworkStats(const string &iface)
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
            NetStats s;
            iss >> name >> s.rxBytes;
            for (int i = 0; i < 7; i++)
            {
                uint64_t tmp;
                iss >> tmp;
            }
            iss >> s.txBytes;
            return s;
        }
    }
    return {};
}

void drawGraph(const vector<int> &rxData, const vector<int> &txData)
{
    cout << "\033[H"; // move to top-left

    int maxRx = max(1, *max_element(rxData.begin(), rxData.end()));
    int maxTx = max(1, *max_element(txData.begin(), txData.end()));

    const string green = "\033[32m"; // RX
    // const string blue = "\033[34m"; //TX
    const string red = "\033[31m"; // TX
    const string reset = "\033[0m";

    // --------- RX Graph ---------
    cout << "RX (bytes/s)\n";
    for (int row = HEIGHT; row > 0; --row)
    {
        int level = (maxRx * row) / HEIGHT;
        cout << setw(8) << level << " | ";
        for (int val : rxData)
        {
            int h = (val * HEIGHT) / maxRx;
            cout << (h >= row ? green + "|" + reset : " ") << " ";
        }
        cout << "\n";
    }
    cout << "         +";
    for (int i = 0; i < WIDTH * 2; ++i)
        cout << "-";
    cout << "\n";

    // --------- TX Graph ---------
    cout << "TX (bytes/s)\n";
    for (int row = HEIGHT; row > 0; --row)
    {
        int level = (maxTx * row) / HEIGHT;
        cout << setw(8) << level << " | ";
        for (int val : txData)
        {
            int h = (val * HEIGHT) / maxTx;
            // cout << (h >= row ? blue + "|" + reset : " ") << " ";
             cout << (h >= row ? red + "|" + reset : " ") << " ";
        }
        cout << "\n";
    }
    cout << "         +";
    for (int i = 0; i < WIDTH * 2; ++i)
        cout << "-";
    cout << "\n";

    // X-axis labels: 1..60 with interval of 5
    cout << "         ";
    for (int i = 0; i < WIDTH; ++i)
    {
        int label = i + 1;
        if (label == 1 || label == WIDTH || label % 5 == 0)
            cout << label << (label < 10 ? " " : "");
        else
            cout << "  ";
    }
    cout << "\n";
}

int main()
{
    // List interfaces
    vector<string> ifaces = listInterfaces();
    if (ifaces.empty())
    {
        cerr << "No interfaces found!\n";
        return 1;
    }

    cout << "Available network interfaces:\n";
    for (size_t i = 0; i < ifaces.size(); ++i)
    {
        cout << i << ": " << ifaces[i] << "\n";
    }

    cout << "Select interface index: ";
    int choice;
    cin >> choice;
    if (choice < 0 || choice >= (int)ifaces.size())
    {
        cerr << "Invalid choice\n";
        return 1;
    }

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    string iface = ifaces[choice];
    cout << "Monitoring interface: " << iface << "\n";
    this_thread::sleep_for(1s);

    // Alternate screen
    cout << "\033[?1049h";

    NetStats prev = readNetworkStats(iface);

    vector<int> rxData(WIDTH, 0);
    vector<int> txData(WIDTH, 0);

    while (true)
    {
        this_thread::sleep_for(1s);
        NetStats now = readNetworkStats(iface);

        uint64_t rxBps = now.rxBytes - prev.rxBytes;
        uint64_t txBps = now.txBytes - prev.txBytes;
        prev = now;

        // shift data right
        for (int i = WIDTH - 1; i > 0; --i)
        {
            rxData[i] = rxData[i - 1];
            txData[i] = txData[i - 1];
        }
        rxData[0] = static_cast<int>(rxBps);
        txData[0] = static_cast<int>(txBps);

        drawGraph(rxData, txData);
        cout << "\nNewest sample at 1 (left). Oldest at 60 (right)\n";
        cout << "Interface: " << iface << "\n";
    }

    cout << "\033[?1049l";
}
