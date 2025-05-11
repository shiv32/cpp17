#include "ConcreteStrategyA.hpp"
#include <algorithm>

std::string ConcreteStrategyA::doAlgorithm(std::string_view data) const
{
    std::string result(data);
    std::sort(std::begin(result), std::end(result));

    return result;
}