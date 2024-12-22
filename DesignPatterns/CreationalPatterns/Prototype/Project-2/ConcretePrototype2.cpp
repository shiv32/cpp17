#include "ConcretePrototype2.hpp"

ConcretePrototype2::ConcretePrototype2(std::string prototype_name, float concrete_prototype_field)
    : Prototype(prototype_name), concrete_prototype_field2_(concrete_prototype_field)
{
}

Prototype *ConcretePrototype2::Clone() const
{
    return new ConcretePrototype2(*this);
}
