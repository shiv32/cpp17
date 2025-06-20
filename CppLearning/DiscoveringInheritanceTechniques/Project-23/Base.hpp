#pragma once

#include <string>

class Base
{
public:
    virtual ~Base() = default;
    Base(std::string_view str);

private:
    std::string mStr;
};