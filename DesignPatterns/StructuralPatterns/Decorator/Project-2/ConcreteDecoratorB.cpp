/**
 * @file ConcreteDecoratorB.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "ConcreteDecoratorB.hpp"
#include <iostream>

ConcreteDecoratorB::~ConcreteDecoratorB()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

ConcreteDecoratorB::ConcreteDecoratorB(Component *component) : Decorator(component)
{
}

std::string ConcreteDecoratorB::Operation() const
{
    return "ConcreteDecoratorB(" + Decorator::Operation() + ")";
}
