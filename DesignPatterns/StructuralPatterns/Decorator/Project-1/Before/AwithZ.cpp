/**
 * @file AwithZ.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "AwithZ.hpp"
#include <iostream>

void AwithZ::do_it()
{
    A::do_it();
    do_Z();
}

void AwithZ::do_Z()
{
    std::cout << 'Z';
}
