#pragma once

#include <string>

class Strategy
{
public:
    virtual ~Strategy() = default;
    virtual std::string doAlgorithm(std::string_view data) const = 0;
};