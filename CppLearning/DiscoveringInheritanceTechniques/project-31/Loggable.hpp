#pragma once

#include <string>

class Loggable
{
public:
    virtual ~Loggable() = default;
    virtual std::string getLogMessage() const = 0;
};