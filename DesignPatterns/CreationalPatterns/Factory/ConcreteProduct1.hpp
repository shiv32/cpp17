#pragma once

#include "Product.hpp"

class ConcreteProduct1 : public Product
{
public:
    std::string Operation() const override;
};