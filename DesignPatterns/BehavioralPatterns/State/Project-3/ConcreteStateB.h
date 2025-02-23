/**
 * @file ConcreteStateB.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once
#include "State.h"

class ConcreteStateB : public State
{

public:
    State *Handle() override;
};
