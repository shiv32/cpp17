#include "Z.hpp"
#include <iostream>

Z::Z(I *core) : D(core) {}

Z::~Z()
{
    std::cout << "Z dtor" << "   ";
}

void Z::do_it()
{
    D::do_it();
    std::cout << 'Z';
}
