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
    std::cout << "Foo Class data name in Bar2 class : " << fo.name << std::endl;
}
