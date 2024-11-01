#include "Foo.hpp"

Foo::Foo(double value) : mValue(value)
{
    std::cout << "Foo::mValue = " << mValue << std::endl;
}