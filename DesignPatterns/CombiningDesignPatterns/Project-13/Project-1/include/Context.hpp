
#pragma once
#include <memory>
#include <string>

class State;

class Context
{
public:
    Context();
    ~Context();

    void setState(std::unique_ptr<State> state);
    void request(const std::string &command);

private:
    std::unique_ptr<State> state_;
};
