#pragma once

#include "AbstractHandler.hpp"

/**
 * All Concrete Handlers either handle a request or pass it to the next handler
 * in the chain.
 */
class MonkeyHandler : public AbstractHandler
{
public:
    std::string Handle(std::string request) override;
};