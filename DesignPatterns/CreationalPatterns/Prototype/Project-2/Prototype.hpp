/**
 * @file Prototype.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-12-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once

/**
 * The example class that has cloning ability. We'll see how the values of field
 * with different types will be cloned.
 */
#include <iostream>

class Prototype
{
protected:
    std::string prototype_name_;
    float prototype_field_;

public:
    Prototype() = default;
    Prototype(std::string prototype_name);

    virtual ~Prototype() = default;
    virtual Prototype *Clone() const = 0;
    virtual void Method(float prototype_field);
};