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