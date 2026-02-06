#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <string>

using ConfigMap = std::unordered_map<std::string, std::string>;

ConfigMap parseConfig(const std::string& file)
{
    ConfigMap config;
    std::ifstream in(file);
    std::string line;

    while (std::getline(in, line))
    {
        if (line.empty()) continue;

        std::istringstream iss(line);
        std::string key, value;

        iss >> key >> value;
        config[key] = value;
    }
    return config;
}

int main()
{
    auto cfg = parseConfig("../conf/config.cfg");

    int maxConn = std::stoi(cfg["max_connections"]);
    std::string level = cfg["log_level"];
    bool cache = (cfg["enable_cache"] == "true");

    std::cout << "Max connections: " << maxConn << "\n";
    std::cout << "Log level: " << level << "\n";
    std::cout << "Cache enabled: " << std::boolalpha << cache << "\n";
}
