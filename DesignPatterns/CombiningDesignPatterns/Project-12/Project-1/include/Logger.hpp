#pragma once
#include <string>
#include <iostream>

class Logger {
public:
    static Logger& getInstance();
    void log(const std::string& msg);

private:
    Logger() = default;
};