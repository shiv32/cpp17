/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief The Need for virtual Destructors
 * @version 0.1
 * @date 2024-08-09
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include "Derived.hpp"

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    Base *ptr = new Derived(); // mString is allocated here.

    delete ptr;                // ~Base is called, but not ~Derived because the destructor
                              // is not virtual!

    return 0;
}