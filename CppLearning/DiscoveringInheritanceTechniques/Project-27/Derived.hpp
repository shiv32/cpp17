#pragma once

#include "Base.hpp"

class Derived : public Base
{
public:
    virtual void go(int i = 7) override;
    // virtual void go(float i = 8.9);  //overloading the go() method with a new non-zero-argument version.
};