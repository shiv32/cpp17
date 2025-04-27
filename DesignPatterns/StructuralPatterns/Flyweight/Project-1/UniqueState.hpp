#pragma once

#include <string>
#include <ostream>

struct UniqueState
{
    std::string owner_;
    std::string plates_;

    UniqueState(const std::string &owner, const std::string &plates);

    friend std::ostream &operator<<(std::ostream &os, const UniqueState &us);
};