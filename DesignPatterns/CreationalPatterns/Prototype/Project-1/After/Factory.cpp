/**
 * @file Factory.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-12-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Factory.hpp"
#include "Larry.hpp"
#include "Moe.hpp"
#include "Curly.hpp"

Stooge *Factory::s_prototypes[] = {0, new Larry, new Moe, new Curly};

Stooge *Factory::make_stooge(int choice)
{
    return s_prototypes[choice]->clone();
}