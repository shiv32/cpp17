#include "AwithY.hpp"
#include <iostream>

void AwithY::do_it()
{
    A::do_it();
    do_Y();
}

void AwithY::do_Y()
{
    std::cout << 'Y';
}
