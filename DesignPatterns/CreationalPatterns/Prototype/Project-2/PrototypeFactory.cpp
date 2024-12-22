/**
 * @file PrototypeFactory.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-12-22
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "PrototypeFactory.hpp"

PrototypeFactory::PrototypeFactory()
{
    prototypes_[Type::PROTOTYPE_1] = new ConcretePrototype1("PROTOTYPE_1 ", 50.f);
    prototypes_[Type::PROTOTYPE_2] = new ConcretePrototype2("PROTOTYPE_2 ", 60.f);
}

PrototypeFactory::~PrototypeFactory()
{
    delete prototypes_[Type::PROTOTYPE_1];
    delete prototypes_[Type::PROTOTYPE_2];
}

Prototype *PrototypeFactory::CreatePrototype(Type type)
{
    return prototypes_[type]->Clone();
}
