#include "Foo.hpp"

Foo::Foo(std::string mname) : name{mname}
{
}

Foo::~Foo()
{
}

std::string Foo::get_name()
{
    return name;
}

void Bar2::ProcessFoo(Foo &fo)
{
    std::cout << "Bar class method make friend of Foo class, name : " << fo.name << std::endl;
}

void dumpFoo(Foo &fo)
{
    std::cout << "Standalone function make friend of Foo class, name : " << fo.name << std::endl;
}