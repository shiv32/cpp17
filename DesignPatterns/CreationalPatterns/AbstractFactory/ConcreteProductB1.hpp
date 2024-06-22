/**
 * Concrete Products are created by corresponding Concrete Factories.
 */

#pragma once

#include "AbstractProductA.hpp"
#include "AbstractProductB.hpp"

class ConcreteProductB1 : public AbstractProductB
{
public:
    std::string UsefulFunctionB() const override;

    /**
     * The variant, Product B1, is only able to work correctly with the variant,
     * Product A1. Nevertheless, it accepts any instance of AbstractProductA as an
     * argument.
     */
    std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const override;
};