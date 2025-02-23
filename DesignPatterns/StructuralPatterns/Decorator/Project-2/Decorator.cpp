/**
 * @file Decorator.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "Decorator.hpp"

Decorator::Decorator(Component *component) : component_(component)
{
}

std::string Decorator::Operation() const
{
    return this->component_->Operation();
}