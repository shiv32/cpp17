#pragma once

#include "Foo.hpp"

class MyClass
{
public:
    MyClass(double value);

private:
    double mValue;
    Foo mFoo;

    // just reverse the order of the mValue and mFoo data members
    //  Foo mFoo;
    //  double mValue;
};