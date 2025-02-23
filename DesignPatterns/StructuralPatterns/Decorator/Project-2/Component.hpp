/**
 * @file Component.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
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