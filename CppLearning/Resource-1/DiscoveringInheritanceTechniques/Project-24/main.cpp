/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief The Base Class Method Is static
 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include "DerivedStatic.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // BaseStatic::beStatic();
    // DerivedStatic::beStatic();

    DerivedStatic myDerivedStatic;
    BaseStatic &ref = myDerivedStatic;
    myDerivedStatic.beStatic();
    ref.beStatic();

    return 0;
}