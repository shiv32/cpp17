/**
 * @file Machine.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-10-24
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "Machine.hpp"

Machine::Machine()
{
    current = new OFF();
    std::cout << '\n';
}

void Machine::setCurrent(State *s)
{
    current = s;
}

void Machine::on()
{
    current->on(this);
}

void Machine::off()
{
    current->off(this);
}
