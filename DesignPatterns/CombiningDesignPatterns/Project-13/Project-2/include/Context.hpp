
#pragma once
#include <memory>
#include <string>
#include "Observer.hpp"

class State;

class Context : public Subject {
public:
    Context();
    ~Context();

    void setState(std::unique_ptr<State> state);
    void request(const std::string& command);
    std::string getCurrentStateName() const;

private:
    std::unique_ptr<State> state_;
    std::string stateName_;
};
