#pragma once

/**
 * The Product interface declares the operations that all concrete products must
 * implement.
 */

#include <string>

class Product
{
public:
    virtual ~Product() {}
    virtual std::string Operation() const = 0;
};