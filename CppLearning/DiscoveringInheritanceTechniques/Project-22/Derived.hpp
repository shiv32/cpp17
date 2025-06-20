/**
 * @file Derived.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-10-25
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once
#include "Base1.hpp"
#include "Base2.hpp"

class Derived : public Base1, public Base2
{
public:
    using Base1::Base1;
    using Base2::Base2;
    Derived(char c);
    Derived(float f);
};