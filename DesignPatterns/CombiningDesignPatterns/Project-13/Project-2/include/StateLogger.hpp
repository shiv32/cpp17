
#pragma once
#include "Observer.hpp"
#include <iostream>

class StateLogger : public Observer {
public:
    void update(const std::string& state) override {
        std::cout << "[StateLogger] New state: " << state << std::endl;
    }
};
