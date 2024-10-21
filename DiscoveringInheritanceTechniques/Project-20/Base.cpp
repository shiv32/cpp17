#include "Base.hpp"
#include <iostream>

void Base::someMethod()
{
     std::cout << __PRETTY_FUNCTION__ << std::endl;
}