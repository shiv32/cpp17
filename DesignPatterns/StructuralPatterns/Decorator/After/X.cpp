#include "X.hpp"
#include <iostream>

X::X(I *core) : D(core) 
{
    
}

X::~X()
{
    std::cout << "X dtor" << "   ";
}

void X::do_it()
{
    D::do_it();
    std::cout << 'X';
}
