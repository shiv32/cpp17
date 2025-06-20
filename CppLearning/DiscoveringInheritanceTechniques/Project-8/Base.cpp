/**
 * @file Base.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-08-28
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Base.hpp"

Base::Base()
{
    std::cout << "1" << std::endl;
}

Base::Base(int i) : Base()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
