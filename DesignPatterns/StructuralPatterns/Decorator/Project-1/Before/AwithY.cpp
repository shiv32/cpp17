/**
 * @file AwithY.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "AwithY.hpp"
#include <iostream>

void AwithY::do_it()
{
    A::do_it();
    do_Y();
}

void AwithY::do_Y()
{
    std::cout << 'Y';
}
