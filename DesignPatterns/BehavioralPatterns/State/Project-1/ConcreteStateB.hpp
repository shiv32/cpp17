/**
 * @file ConcreteStateB.hpp
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

class ConcreteStateB : public State
{
public:
    void Handle1() override;
    void Handle2() override;
};