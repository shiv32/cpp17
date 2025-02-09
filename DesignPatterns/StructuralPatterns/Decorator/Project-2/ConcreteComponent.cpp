#include "ConcreteComponent.hpp"
#include <iostream>

ConcreteComponent::~ConcreteComponent() 
{
    std::cout<<__PRETTY_FUNCTION__<<std::endl;
}

std::string ConcreteComponent::Operation() const { return "ConcreteComponent"; }