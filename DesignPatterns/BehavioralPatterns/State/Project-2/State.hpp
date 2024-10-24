/**
 * @file State.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-10-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <iostream>

class Machine;

class State
{
public:
    virtual void on(Machine *m);
    virtual void off(Machine *m);
};