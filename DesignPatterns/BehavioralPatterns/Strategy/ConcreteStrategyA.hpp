#pragma once

#include "Strategy.hpp"

class ConcreteStrategyA : public Strategy
{
public:
    std::string doAlgorithm(std::string_view data) const override;
};
