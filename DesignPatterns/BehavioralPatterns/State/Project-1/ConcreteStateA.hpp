/**
 * @file ConcreteStateA.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-10-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include "State.hpp"

/**
 * Concrete States implement various behaviors, associated with a state of the
 * Context.
 */

class ConcreteStateA : public State
{
public:
    void Handle1() override;
    void Handle2() override;
};