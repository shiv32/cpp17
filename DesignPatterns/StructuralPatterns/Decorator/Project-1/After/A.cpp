#include "A.hpp"
#include <iostream>

A::~A()
{
    std::cout << "A dtor" << '\n';
}

void A::do_it()
{
    std::cout << 'A';
}
