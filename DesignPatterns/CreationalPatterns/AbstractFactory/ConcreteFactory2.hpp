/**
 * Each Concrete Factory has a corresponding product variant.
 */

#pragma once

#include "AbstractFactory.hpp"
#include "ConcreteProductA2.hpp"
#include "ConcreteProductB2.hpp"

class ConcreteFactory2 : public AbstractFactory
{
public:
    AbstractProductA *CreateProductA() const override;
    AbstractProductB *CreateProductB() const override;
};