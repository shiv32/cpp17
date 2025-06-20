/**
 * @file Base.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-08-11
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Base.hpp"

void Base::func1() {std::cout << __PRETTY_FUNCTION__ << std::endl;}

void Base::func2() {std::cout << __PRETTY_FUNCTION__ << std::endl;}

void Base::nonVirtualFunc() {std::cout << __PRETTY_FUNCTION__ << std::endl;}
