#include "AwithZ.hpp"
#include <iostream>

void AwithZ::do_it()
{
    A::do_it();
    do_Z();
}

void AwithZ::do_Z()
{
    std::cout << 'Z';
}
