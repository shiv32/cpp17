
#pragma once
#include <string>

class Logger {
public:
    static Logger& getInstance();
    void log(const std::string& message);

private:
    Logger() = default;
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};
