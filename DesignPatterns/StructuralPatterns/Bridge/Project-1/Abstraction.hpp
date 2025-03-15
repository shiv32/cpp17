/**
 * @file Abstraction.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-03-15
 *
 * @copyright Copyright (c) 2025
 *
 */

/**
 * The Abstraction defines the interface for the "control" part of the two class
 * hierarchies. It maintains a reference to an object of the Implementation
 * hierarchy and delegates all of the real work to this object.
 */
#pragma once
#include "Implementation.hpp"

class Abstraction
{
    /**
     * @var Implementation
     */
protected:
    Implementation *implementation_;

public:
    Abstraction(Implementation *implementation);
    virtual ~Abstraction();
    virtual std::string Operation() const;
};