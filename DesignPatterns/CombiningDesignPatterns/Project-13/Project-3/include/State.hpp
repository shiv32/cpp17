#pragma once
#include <string>

class Context;

class State {
public:
    virtual void handle(Context& ctx) = 0;
    virtual std::string name() const = 0;
    virtual ~State() = default;
};