
#pragma once
#include <string>
#include <iostream>

class Logger {
public:
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    void log(const std::string& msg) {
        std::cout << "[LOG]: " << msg << std::endl;
    }

private:
    Logger() = default;
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};
