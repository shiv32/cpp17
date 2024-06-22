#pragma once

/**
 * Concrete Products provide various implementations of the Product interface.
 */

#include "Product.hpp"

class ConcreteProduct2 : public Product
{
public:
    std::string Operation() const override;
};