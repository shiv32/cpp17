/**
 * @file Z.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "Z.hpp"
#include <iostream>

Z::Z(I *core) : D(core) {}

Z::~Z()
{
   std::cout <<__PRETTY_FUNCTION__<<"   ";
}

void Z::do_it()
{
    D::do_it();
    std::cout << 'Z';
}
