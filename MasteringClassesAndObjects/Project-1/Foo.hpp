#pragma once
#include <string>
#include "Bar.hpp"

class Foo;

class Bar2
{
public:
    void ProcessFoo(Foo &fo);
};

class Foo
{
private:
    std::string name{};

public:
    Foo(std::string mname);
    ~Foo();

    std::string get_name();

    friend class Bar;

    friend void Bar2::ProcessFoo(Foo &fo);
};
