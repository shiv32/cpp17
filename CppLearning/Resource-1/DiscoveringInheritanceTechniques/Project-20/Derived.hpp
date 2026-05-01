#pragma once

#include "Base.hpp"

class Derived : public Base
{
public:
    using Base::someMethod;         // Explicitly "inherits" the Base version
    virtual void someMethod(int i); // Compiles, but doesn't override
                                    // Adds a new version of someMethod
    virtual void someOtherMethod();
};