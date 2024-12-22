/**
 * @file ConcretePrototype1.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-12-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "ConcretePrototype1.hpp"

ConcretePrototype1::ConcretePrototype1(std::string prototype_name, float concrete_prototype_field)
    : Prototype(prototype_name), concrete_prototype_field1_(concrete_prototype_field)
{
}

Prototype *ConcretePrototype1::Clone() const
{
    return new ConcretePrototype1(*this);
}