#pragma once

#include <string>
#include <ostream>

struct SharedState
{
    std::string brand_;
    std::string model_;
    std::string color_;

    SharedState(const std::string &brand, const std::string &model, const std::string &color);

    friend std::ostream &operator<<(std::ostream &os, const SharedState &ss);
};