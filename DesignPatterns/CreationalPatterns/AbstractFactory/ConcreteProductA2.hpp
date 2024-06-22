/**
 * Concrete Products are created by corresponding Concrete Factories.
 */

#pragma once

#include "AbstractProductA.hpp"

class ConcreteProductA2 : public AbstractProductA
{
public:
    std::string UsefulFunctionA() const override;
};