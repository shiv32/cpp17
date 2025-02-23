/**
 * @file ConcreteDecoratorB.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once
#include "Decorator.hpp"
/**
 * Decorators can execute their behavior either before or after the call to a
 * wrapped object.
 */
class ConcreteDecoratorB : public Decorator
{
public:
    ~ConcreteDecoratorB();
    ConcreteDecoratorB(Component *component);
    std::string Operation() const override;
};