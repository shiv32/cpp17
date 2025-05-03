#pragma once

#include "Product.hpp"

class ConcreteProduct2 : public Product
{
public:
    std::string Operation() const override;
};