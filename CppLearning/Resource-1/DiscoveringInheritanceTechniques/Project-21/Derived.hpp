#pragma once

#include "Base.hpp"

class Derived : public Base
{
public:
    using Base::Base;
    Derived(int i);
    Derived(float f); // Overrides inherited float Base ctor
};