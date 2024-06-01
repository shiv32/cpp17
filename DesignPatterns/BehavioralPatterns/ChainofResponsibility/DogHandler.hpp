#pragma once

#include "AbstractHandler.hpp"

class DogHandler : public AbstractHandler
{
public:
    std::string Handle(std::string request) override;
};