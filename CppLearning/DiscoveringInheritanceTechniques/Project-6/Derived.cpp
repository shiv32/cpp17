/**
 * @file Derived.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-08-11
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Derived.hpp"

Derived::Derived()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    mString = new char[30];
    std::cout << "mString allocated" << std::endl;
}

Derived::~Derived()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    
    delete[] mString;
    std::cout << "mString deallocated" << std::endl;
}
