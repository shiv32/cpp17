/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief The Base Class Method Is Overloaded
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

    // Derived myDerived;
    // myDerived.overload(2); // Error! No matching method for overload(int). without using Base::overload

    // Derived myDerived;
    // Base &ref = myDerived; // a simple cast to the base class brings them right back
    // ref.overload(7);

    Derived myDerived;
    myDerived.overload(2); // with using Base::overload

    return 0;
}