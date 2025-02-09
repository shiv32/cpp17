#include "ConcreteDecoratorA.hpp"
#include<iostream>

ConcreteDecoratorA::~ConcreteDecoratorA() 
{
     std::cout<<__PRETTY_FUNCTION__<<std::endl;
}

ConcreteDecoratorA::ConcreteDecoratorA(Component *component)
    : Decorator(component) {}

std::string ConcreteDecoratorA::Operation() const
{
    return "ConcreteDecoratorA(" + Decorator::Operation() + ")";
}
