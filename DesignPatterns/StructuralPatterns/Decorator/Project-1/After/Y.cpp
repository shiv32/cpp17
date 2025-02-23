/**
 * @file Y.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "Y.hpp"
#include <iostream>

Y::Y(I *core) : D(core) {}

Y::~Y()
{
    std::cout <<__PRETTY_FUNCTION__<<"   ";
}

void Y::do_it()
{
    D::do_it();
    std::cout << 'Y';
}
