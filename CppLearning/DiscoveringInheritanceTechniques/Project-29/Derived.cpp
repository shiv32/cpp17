#include "Derived.hpp"
#include <iostream>

Derived::Derived()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

// Derived::Derived(const Derived &src)
// {
//     std::cout << __PRETTY_FUNCTION__ << std::endl;
// }

Derived::Derived(const Derived &src) : Base(src)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

Derived &Derived::operator=(const Derived &rhs)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    if (&rhs == this)
    {
        return *this;
    }

    Base::operator=(rhs); // Calls parent's operator=.

    // Do necessary assignments for derived class.

    return *this;
}
