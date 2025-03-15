/**
 * @file ExtendedAbstraction.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-03-15
 *
 * @copyright Copyright (c) 2025
 *
 */
#pragma once
#include "Abstraction.hpp"

/**
 * You can extend the Abstraction without changing the Implementation classes.
 */
class ExtendedAbstraction : public Abstraction
{
public:
    ExtendedAbstraction(Implementation *implementation);
    virtual ~ExtendedAbstraction();
    std::string Operation() const override;
};