
#pragma once
#include <string>
#include <iostream>

class Logger {
public:
    static Logger& getInstance();
    void log(const std::string& msg);

private:
    Logger() = default;
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};
