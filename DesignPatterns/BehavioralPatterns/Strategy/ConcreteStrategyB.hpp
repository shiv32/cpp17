#pragma once

#include "Strategy.hpp"

class ConcreteStrategyB : public Strategy
{
public:
    std::string doAlgorithm(std::string_view data) const override;
};