#pragma once

#include "Creator.hpp"
#include "ConcreteProduct1.hpp"

class ConcreteCreator1 : public Creator
{
public:
    Product *FactoryMethod() const override;
};