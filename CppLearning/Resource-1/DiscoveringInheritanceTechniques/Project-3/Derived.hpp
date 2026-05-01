/**
 * @file Derived.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-08-11
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once
#include "Base.hpp"

class Derived : public Base
{
public:
     virtual void someMethod(double d);

    // virtual void someMethod(int i);

    //virtual void someMethod(int i) override;

    virtual void someOtherMethod();
};