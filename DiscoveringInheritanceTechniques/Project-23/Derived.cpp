#include "Derived.hpp"
#include <iostream>

Derived::Derived(int i) : Base(""), mInt(i) 
{
    std::cout<<__PRETTY_FUNCTION__<<std::endl;

    std::cout<<"mInt : "<<mInt<<std::endl;
}
