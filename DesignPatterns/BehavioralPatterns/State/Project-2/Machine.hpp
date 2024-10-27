/**
 * @file Machine.hpp
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
#include "OFF.hpp"

class Machine
{
    class State *current;

public:
    Machine();
    void setCurrent(State *s);

    void on();
    void off();
};