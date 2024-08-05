/**
 * @file DogHandler.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include "AbstractHandler.hpp"

class DogHandler : public AbstractHandler
{
public:
    void HandlerName() override;
    std::string Handle(std::string request) override;
};