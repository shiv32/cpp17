#pragma once

#include "Base.hpp"

class Derived : public Base
{
public:
    using Base::Base;
    Derived(int i);

private:
    //int mInt;
     int mInt = 0;  //in-class member initializer
};