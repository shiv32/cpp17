#pragma once

#include <iostream>
#include <string>
#include "Bar2.hpp"

class Foo
{
private:
    std::string name{};

public:
    Foo(std::string mname);
    ~Foo();

    std::string get_name();

    friend class Bar; // Bar class is a friend of Foo class

    friend void Bar2::ProcessFoo(Foo &fo);

    friend void dumpFoo(Foo &fo);
};
