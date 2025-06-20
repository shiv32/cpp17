#include "Base2.hpp"
#include <iostream>

Base2::Base2(std::string_view str)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

Base2::Base2(float f)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
