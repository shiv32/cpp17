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

void Derived::func2() {std::cout << __PRETTY_FUNCTION__ << std::endl;}

void Derived::nonVirtualFunc() {std::cout << __PRETTY_FUNCTION__ << std::endl;}

void Derived::nonVirtualFunc2()  {std::cout << __PRETTY_FUNCTION__ << std::endl;}
