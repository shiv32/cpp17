/**
 * Each distinct product of a product family should have a base interface. All
 * variants of the product must implement this interface.
 */

#pragma once

#include <string>

class AbstractProductA
{
public:
    virtual ~AbstractProductA(){};
    virtual std::string UsefulFunctionA() const = 0;
};