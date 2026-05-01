/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief The Truth about virtual
 * @version 0.1
 * @date 2024-08-09
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>

#include "Derived.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    Derived myDerived;
    myDerived.go();

    Base &ref = myDerived;
    ref.go();

    return 0;
}