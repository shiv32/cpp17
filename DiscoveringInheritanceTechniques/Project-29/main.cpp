/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Copy Constructors and Assignment Operators in Derived Classes
 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include "Derived.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Base bs;
    // Base bs1(bs);

    Derived dr;

    std::cout << "---------------------" << std::endl;

    Derived dr1(dr); // call copy ctor

    std::cout << "---------------------" << std::endl;

    dr1 = dr; // call copy assignment operator

    return 0;
}