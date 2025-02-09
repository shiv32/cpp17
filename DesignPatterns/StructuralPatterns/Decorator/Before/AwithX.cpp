#include "AwithX.hpp"
#include <iostream>

void AwithX::do_it()
{
    A::do_it();
    do_X();
}

void AwithX::do_X()
{
    std::cout << 'X';
}
