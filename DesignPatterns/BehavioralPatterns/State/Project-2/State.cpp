/**
 * @file State.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-10-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "State.hpp"

void State::on(Machine *m)
{
    std::cout << "   already ON\n";
}

void State::off(Machine *m)
{
    std::cout << "   already OFF\n";
}