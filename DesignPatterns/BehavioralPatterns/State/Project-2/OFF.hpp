/**
 * @file OFF.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-10-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include "State.hpp"
#include "ON.hpp"
#include "Machine.hpp"

class Machine;

class OFF : public State
{
public:
    OFF();
    ~OFF();
    void on(Machine *m);
};