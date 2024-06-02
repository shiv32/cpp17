#pragma once

#include "AbstractHandler.hpp"

class SquirrelHandler : public AbstractHandler
{
public:
    void HandlerName() override;
    std::string Handle(std::string request) override;
};