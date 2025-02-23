/**
 * @file A.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "A.hpp"
#include <iostream>

A::~A()
{
    std::cout <<__PRETTY_FUNCTION__<< '\n';
}

void A::do_it()
{
    std::cout << 'A';
}
