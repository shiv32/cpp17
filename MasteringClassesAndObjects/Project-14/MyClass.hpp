#pragma once

#include <iostream>

class MyClass
{
public:
    void foo(int i);
    void foo(double d) = delete;
};