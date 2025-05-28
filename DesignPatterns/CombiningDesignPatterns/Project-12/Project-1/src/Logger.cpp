#include "Logger.hpp"

Logger &Logger::getInstance()
{
    static Logger instance;
    return instance;
}

void Logger::log(const std::string &msg)
{
    std::cout << "[LOG] " << msg << std::endl;
}