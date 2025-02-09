#pragma once

#include<string>

/**
 * The base Component interface defines operations that can be altered by
 * decorators.
 */
class Component
{
public:
    virtual ~Component() = default;
    virtual std::string Operation() const = 0;
};