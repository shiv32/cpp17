#pragma once
#include "Base.hpp"

class Derived : public Base
{
public:
    Derived();
    Derived(const Derived &src);
    Derived& operator=(const Derived& rhs);
};