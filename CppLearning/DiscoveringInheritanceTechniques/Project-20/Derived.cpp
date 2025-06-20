#include "Derived.hpp"
#include <iostream>

void Derived::someMethod(int i)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    std::cout << "This is Derived's version of someMethod with argument " << i
              << "." << std::endl;
}

void Derived::someOtherMethod()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
