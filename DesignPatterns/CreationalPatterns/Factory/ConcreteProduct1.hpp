#pragma once

/**
 * Concrete Products provide various implementations of the Product interface.
 */

#include "Product.hpp"

class ConcreteProduct1 : public Product
{
public:
    std::string Operation() const override;
};