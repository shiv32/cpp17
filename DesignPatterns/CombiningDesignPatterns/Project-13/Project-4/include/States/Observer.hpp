#pragma once
#include <string>
#include <iostream>

class IObserver {
public:
    virtual void onStateChanged(const std::string& newState) = 0;
};

class Logger : public IObserver {
public:
    void onStateChanged(const std::string& state) override {
        std::cout << "[Logger] State changed to: " << state << std::endl;
    }
};