#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <sstream>
#include <unordered_map>

struct NetStats {
    unsigned long rx_bytes = 0;
    unsigned long tx_bytes = 0;
};

std::unordered_map<std::string, NetStats> read_netdev() {
    std::unordered_map<std::string, NetStats> stats;
    std::ifstream file("/proc/net/dev");
    std::string line;
    // skip 2 header lines
    std::getline(file, line);
    std::getline(file, line);
    while (std::getline(file, line)) {
        auto colon = line.find(':');
        if (colon == std::string::npos) continue;
        std::string iface = line.substr(0, colon);
        iface.erase(0, iface.find_first_not_of(" "));
        unsigned long rx, tx;
        // extract first and ninth number
        std::istringstream iss(line.substr(colon + 1));
        iss >> rx; // receive bytes
        for (int i = 0; i < 7; ++i) iss >> std::ws; // skip unused
        iss >> tx; // transmit bytes
        stats[iface] = {rx, tx};
    }
    return stats;
}

int main() {
    using namespace std::chrono_literals;
    auto prev = read_netdev();
    while (true) {
        std::this_thread::sleep_for(1s);
        auto curr = read_netdev();
        system("clear"); // clear terminal
        std::cout << "Interface    RX (KB/s)    TX (KB/s)\n";
        std::cout << "------------------------------------\n";
        for (auto &[iface, now] : curr) {
            auto &old = prev[iface];
            double rx_kbps = (now.rx_bytes - old.rx_bytes) / 1024.0;
            double tx_kbps = (now.tx_bytes - old.tx_bytes) / 1024.0;
            std::cout << iface << "\t" << rx_kbps << "\t" << tx_kbps << "\n";
        }
        prev = curr;
    }
}
