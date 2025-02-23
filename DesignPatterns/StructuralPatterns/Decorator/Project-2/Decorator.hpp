/**
 * @file Decorator.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once

#include "Component.hpp"

/**
 * The base Decorator class follows the same interface as the other components.
 * The primary purpose of this class is to define the wrapping interface for all
 * concrete decorators. The default implementation of the wrapping code might
 * include a field for storing a wrapped component and the means to initialize
 * it.
 */
class Decorator : public Component
{
    /**
     * @var Component
     */
protected:
    Component *component_;

public:
    Decorator(Component *component);

    /**
     * The Decorator delegates all work to the wrapped component.
     */
    std::string Operation() const override;
};