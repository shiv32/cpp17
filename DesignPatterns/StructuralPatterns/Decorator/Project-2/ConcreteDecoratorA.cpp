/**
 * @file ConcreteDecoratorA.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "ConcreteDecoratorA.hpp"
#include <iostream>

ConcreteDecoratorA::~ConcreteDecoratorA()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

ConcreteDecoratorA::ConcreteDecoratorA(Component *component) : Decorator(component)
{
}

std::string ConcreteDecoratorA::Operation() const
{
    return "ConcreteDecoratorA(" + Decorator::Operation() + ")";
}
