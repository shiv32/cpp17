#include "Base.hpp"
#include <iostream>

Base::Base(std::string_view str)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

Base::Base(float f)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
