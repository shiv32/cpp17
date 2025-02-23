/**
 * @file X.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "X.hpp"
#include <iostream>

X::X(I *core) : D(core) 
{
    
}

X::~X()
{
    std::cout << "X dtor" << "   ";
}

void X::do_it()
{
    D::do_it();
    std::cout << 'X';
}
