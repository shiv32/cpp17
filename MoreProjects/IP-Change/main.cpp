#include "NetworkConfig.hpp"
#include <iostream>
#include <string>

int main() {

    std::string interface = "enp0s3";

    auto& net = NetworkConfig::instance();

    // 1. Show current values
    std::string curIp   = net.getIp(interface);
    std::string curMask = net.getSubnetMask(interface);
    std::string curGw   = net.getGateway();

    std::cout << "Current configuration:\n";
    std::cout << "IP Address : " << curIp   << "\n";
    std::cout << "Subnet Mask: " << curMask << "\n";
    std::cout << "Gateway    : " << curGw   << "\n";

    // 2. Ask user if they want to change
    std::cout << "\nDo you want to set new values? (y/n): ";
    char ans;
    std::cin >> ans;
    if (ans != 'y' && ans != 'Y') {
        std::cout << "No changes applied.\n";
        return 0;
    }

    std::string ip, mask, gw;
    std::cout << "Enter new IP (e.g. 192.168.1.50): ";
    std::cin >> ip;
    std::cout << "Enter new subnet (CIDR, e.g. 24): ";
    std::cin >> mask;
    std::cout << "Enter new gateway: ";
    std::cin >> gw;

    net.setIp(ip);
    net.setSubnetMask(mask);
    net.setGateway(gw);

    if (net.apply(interface))
        std::cout << "New configuration applied.\n";
    else
        std::cerr << "Failed to apply configuration.\n";

    return 0;
}
