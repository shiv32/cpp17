#include "Base.hpp"
#include <iostream>

void Base::overload()
{
    std::cout << "Base's overload()" << std::endl;
}

void Base::overload(int i)
{
    std::cout << "Base's overload(int i)" << std::endl;
}
