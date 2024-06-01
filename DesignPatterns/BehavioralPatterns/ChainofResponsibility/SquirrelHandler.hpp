#pragma once

#include "AbstractHandler.hpp"

class SquirrelHandler : public AbstractHandler
{
public:
    std::string Handle(std::string request) override;
};