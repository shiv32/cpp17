#include "Base.hpp"
#include <iostream>

Base::Base()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

Base::Base(const Base &src)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

Base &Base::operator=(const Base &rhs)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
