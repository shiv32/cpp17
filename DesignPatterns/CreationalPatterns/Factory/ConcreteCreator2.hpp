#pragma once

#include "Creator.hpp"
#include "ConcreteProduct2.hpp"

class ConcreteCreator2 : public Creator
{
public:
    Product *FactoryMethod() const override;
};