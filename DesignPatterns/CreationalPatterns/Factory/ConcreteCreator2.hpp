#pragma once

/**
 * Concrete Creators override the factory method in order to change the
 * resulting product's type.
 */

#include "Creator.hpp"
#include "ConcreteProduct2.hpp"

class ConcreteCreator2 : public Creator
{
public:
    Product *FactoryMethod() const override;
};