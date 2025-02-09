#include "Y.hpp"
#include <iostream>

Y::Y(I *core) : D(core) {}

Y::~Y()
{
    std::cout << "Y dtor" << "   ";
}

void Y::do_it()
{
    D::do_it();
    std::cout << 'Y';
}
