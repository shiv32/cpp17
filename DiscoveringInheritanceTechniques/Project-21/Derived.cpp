#include "Derived.hpp"
#include <iostream>

Derived::Derived(int i)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

Derived::Derived(float f)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
