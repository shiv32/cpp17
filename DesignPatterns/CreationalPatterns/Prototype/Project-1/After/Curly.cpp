/**
 * @file Curly.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-12-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Curly.hpp"
#include <iostream>

void Curly::slap_stick()
{
    std::cout << "Curly: suffer abuse\n";
}

Stooge *Curly::clone()
{
    return new Curly;
}