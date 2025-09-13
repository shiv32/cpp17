#include "NetworkConfig.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <sys/ioctl.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstdlib>

NetworkConfig& NetworkConfig::instance() {
    static NetworkConfig inst;
    return inst;
}

std::string NetworkConfig::getIp(const std::string& iface) {
    int fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd < 0) return "";
    ifreq ifr{};
    std::strncpy(ifr.ifr_name, iface.c_str(), IFNAMSIZ);
    if (ioctl(fd, SIOCGIFADDR, &ifr) == 0) {
        auto* ip = (sockaddr_in*)&ifr.ifr_addr;
        close(fd);
        return inet_ntoa(ip->sin_addr);
    }
    close(fd);
    return "";
}

std::string NetworkConfig::getSubnetMask(const std::string& iface) {
    int fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd < 0) return "";
    ifreq ifr{};
    std::strncpy(ifr.ifr_name, iface.c_str(), IFNAMSIZ);
    if (ioctl(fd, SIOCGIFNETMASK, &ifr) == 0) {
        auto* mask = (sockaddr_in*)&ifr.ifr_netmask;
        close(fd);
        return inet_ntoa(mask->sin_addr);
    }
    close(fd);
    return "";
}

std::string NetworkConfig::getGateway() {
    std::ifstream f("/proc/net/route");
    std::string line, iface, dest, gateway;
    while (std::getline(f, line)) {
        std::istringstream iss(line);
        if (iss >> iface >> dest >> gateway) {
            if (dest == "00000000") {
                unsigned long g;
                std::stringstream ss;
                ss << std::hex << gateway;
                ss >> g;
                in_addr gw_addr{ (in_addr_t)g };
                return inet_ntoa(gw_addr);
            }
        }
    }
    return "";
}

// setters
void NetworkConfig::setIp(const std::string& ip)        { ip_  = ip; }
void NetworkConfig::setSubnetMask(const std::string& m) { mask_ = m; }
void NetworkConfig::setGateway(const std::string& gw)   { gw_  = gw; }

bool NetworkConfig::apply(const std::string& iface) {
    if (ip_.empty() || mask_.empty()) {
        std::cerr << "IP or mask missing\n";
        return false;
    }
    std::ostringstream cmd;
    cmd << "ip addr flush dev " << iface
        << " && ip addr add " << ip_ << "/" << mask_
        << " dev " << iface
        << " && ip link set " << iface << " up";
    if (std::system(cmd.str().c_str()) != 0) return false;

    if (!gw_.empty()) {
        std::string gwCmd = "ip route replace default via " + gw_ + " dev " + iface;
        if (std::system(gwCmd.c_str()) != 0) return false;
    }
    return true;
}
