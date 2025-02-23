/**
 * @file ConcreteComponent.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "ConcreteComponent.hpp"
#include <iostream>

ConcreteComponent::~ConcreteComponent()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

std::string ConcreteComponent::Operation() const
{
    return "ConcreteComponent";
}