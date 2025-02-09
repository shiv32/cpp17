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
