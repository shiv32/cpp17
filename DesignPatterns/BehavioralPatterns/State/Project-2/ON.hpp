/**
 * @file ON.hpp
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
#include "Machine.hpp"

class ON : public State
{
public:
    ON();
    ~ON();
    void off(Machine *m);
};
