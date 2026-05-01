#pragma once

#include <iostream>
#include "Foo.hpp"

class Foo;

class Bar
{
public:
    Bar();
    ~Bar();
    void displayClassFooData(Foo &fo);
};
