/**
 * @file Moe.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-12-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Moe.hpp"
#include <iostream>

void Moe::slap_stick()
{
    std::cout << "Moe: slap head\n";
}

Stooge *Moe::clone()
{
    return new Moe;
}