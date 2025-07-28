#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <thread>
#include <chrono>
#include <random>
#include <algorithm>
#include <iomanip>
#include <string>
#include <unistd.h>

using namespace std;

const int WIDTH  = 60;  // X-axis: 60 samples
const int HEIGHT = 10;  // Y-axis height per graph

struct NetStats {
    uint64_t rxBytes = 0;
    uint64_t txBytes = 0;
};

NetStats readNetworkStats(const string& iface) {
    ifstream file("/proc/net/dev");
    string line;
    while (getline(file, line)) {
        if (line.find(iface + ":") != string::npos) {
            replace(line.begin(), line.end(), ':', ' ');
            istringstream iss(line);
            string name;
            NetStats s;
            iss >> name >> s.rxBytes;
            for (int i = 0; i < 7; i++) { uint64_t tmp; iss >> tmp; }
            iss >> s.txBytes;
            return s;
        }
    }
    return {};
}

void drawGraph(const vector<int>& rxData, const vector<int>& txData) {
    cout << "\033[H"; // move cursor to top-left

    int maxRx = max(1, *max_element(rxData.begin(), rxData.end()));
    int maxTx = max(1, *max_element(txData.begin(), txData.end()));

    const string green = "\033[32m";
    const string blue  = "\033[34m";
    const string reset = "\033[0m";

    // --------- RX Graph ---------
    cout << "RX (bytes/s)\n";
    for (int row = HEIGHT; row > 0; --row) {
        int level = (maxRx * row) / HEIGHT;
        cout << setw(8) << level << " | ";
        for (int val : rxData) {
            int h = (val * HEIGHT) / maxRx;
            cout << (h >= row ? green + "|" + reset : " ") << " ";
        }
        cout << "\n";
    }
    cout << "         +";
    for (int i = 0; i < WIDTH * 2; ++i) cout << "-";
    cout << "\n";

    // --------- TX Graph ---------
    cout << "TX (bytes/s)\n";
    for (int row = HEIGHT; row > 0; --row) {
        int level = (maxTx * row) / HEIGHT;
        cout << setw(8) << level << " | ";
        for (int val : txData) {
            int h = (val * HEIGHT) / maxTx;
            cout << (h >= row ? blue + "|" + reset : " ") << " ";
        }
        cout << "\n";
    }
    cout << "         +";
    for (int i = 0; i < WIDTH * 2; ++i) cout << "-";
    cout << "\n";

    // X-axis labels: 1..60 with interval of 5
    cout << "         ";
    for (int i = 0; i < WIDTH; ++i) {
        int label = i + 1; // because you want 1..60
        if (label == 1 || label == WIDTH || label % 5 == 0)
            cout << label << (label < 10 ? " " : ""); // align
        else
            cout << "  ";
    }
    cout << "\n";
}

int main() {
    cout << "\033[?1049h"; // alternate screen

    // string iface = "eth0"; // change to your interface
     string iface = "wlp41s0f4u1"; // Change to your network interface
    NetStats prev = readNetworkStats(iface);

    vector<int> rxData(WIDTH, 0);
    vector<int> txData(WIDTH, 0);

    while (true) {
        this_thread::sleep_for(1s);
        NetStats now = readNetworkStats(iface);

        uint64_t rxBps = now.rxBytes - prev.rxBytes;
        uint64_t txBps = now.txBytes - prev.txBytes;
        prev = now;

        // shift data right
        for (int i = WIDTH - 1; i > 0; --i) {
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
