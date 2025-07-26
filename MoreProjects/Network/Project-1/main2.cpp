#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <thread>
#include <chrono>
#include <unordered_map>
#include <iomanip>
#include <cstdlib> // for system("clear")

struct NetStats {
    unsigned long rx_bytes = 0;
    unsigned long tx_bytes = 0;
};

// ANSI color codes for terminal
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string RESET = "\033[0m";

std::unordered_map<std::string, NetStats> read_netdev() {
    std::unordered_map<std::string, NetStats> stats;
    std::ifstream file("/proc/net/dev");
    std::string line;
    // skip header lines
    std::getline(file, line);
    std::getline(file, line);

    while (std::getline(file, line)) {
        auto colon = line.find(':');
        if (colon == std::string::npos) continue;
        std::string iface = line.substr(0, colon);
        iface.erase(0, iface.find_first_not_of(" ")); // trim leading spaces
        unsigned long rx, tx;
        std::istringstream iss(line.substr(colon + 1));
        iss >> rx; 
        for (int i = 0; i < 7; ++i) iss >> std::ws; 
        iss >> tx;
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
        system("clear");

        std::cout << std::left
                  << std::setw(15) << "Interface"
                  << std::setw(15) << "RX (KB/s)"
                  << std::setw(15) << "TX (KB/s)" << "\n";
        std::cout << std::string(45, '-') << "\n";

        for (auto &[iface, now] : curr) {
            auto &old = prev[iface];
            double rx_kbps = (now.rx_bytes - old.rx_bytes) / 1024.0;
            double tx_kbps = (now.tx_bytes - old.tx_bytes) / 1024.0;

            // Choose color based on RX speed
            std::string rxColor = (rx_kbps > 100.0) ? RED : GREEN;
            std::string txColor = (tx_kbps > 100.0) ? RED : GREEN;

            std::cout << std::left << std::setw(15) << iface
                      << rxColor << std::setw(15) << std::fixed << std::setprecision(2) << rx_kbps << RESET
                      << txColor << std::setw(15) << std::fixed << std::setprecision(2) << tx_kbps << RESET
                      << "\n";
        }

        prev = curr;
    }
}
