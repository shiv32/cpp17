#include "Derived.hpp"
#include <iostream>

Derived::Derived(char c)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

// Derived::Derived(float f)
// {
//     std::cout << __PRETTY_FUNCTION__ << std::endl;
// }

Derived::Derived(float f) : Base1(f), Base2(f)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
