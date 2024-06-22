/**
 * Concrete Factories produce a family of products that belong to a single
 * variant. The factory guarantees that resulting products are compatible. Note
 * that signatures of the Concrete Factory's methods return an abstract product,
 * while inside the method a concrete product is instantiated.
 */

#pragma once

#include "AbstractFactory.hpp"
#include "ConcreteProductA1.hpp"
#include "ConcreteProductB1.hpp"

class ConcreteFactory1 : public AbstractFactory
{
public:
    AbstractProductA *CreateProductA() const override;
    AbstractProductB *CreateProductB() const override;
};