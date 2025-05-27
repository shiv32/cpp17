
#pragma once
#include <memory>
#include <string>

class Context;

class State
{
public:
    virtual ~State() = default;
    virtual void handle(Context &context, const std::string &command) = 0;
};
