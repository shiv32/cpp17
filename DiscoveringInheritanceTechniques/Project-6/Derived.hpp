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
     Derived();
     //virtual void someMethod() override; //compilation error because someMethod() is 
                                         //marked as final in the Base class

     ~Derived();
     //virtual ~Derived();

private:
     char *mString;
};