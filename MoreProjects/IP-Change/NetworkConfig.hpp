#pragma once
#include <string>

class NetworkConfig {
public:
    static NetworkConfig& instance();

    // current values read from the system
    std::string getIp(const std::string& iface = "eth0");
    std::string getSubnetMask(const std::string& iface = "eth0");
    std::string getGateway();

    // setters for new values
    void setIp(const std::string& ip);
    void setSubnetMask(const std::string& maskCIDR);
    void setGateway(const std::string& gw);

    // apply new settings
    bool apply(const std::string& iface = "eth0");

private:
    NetworkConfig() = default;
    ~NetworkConfig() = default;
    NetworkConfig(const NetworkConfig&) = delete;
    NetworkConfig& operator=(const NetworkConfig&) = delete;

    std::string ip_, mask_, gw_;
};
