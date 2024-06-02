#pragma once

#include "AbstractHandler.hpp"

class DogHandler : public AbstractHandler
{
public:
    void HandlerName() override;
    std::string Handle(std::string request) override;
};