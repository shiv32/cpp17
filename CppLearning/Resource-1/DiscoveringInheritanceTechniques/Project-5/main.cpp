/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief How virtual Is Implemented
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

    Base myBase;

    myBase.func1();
    myBase.func2();
    myBase.nonVirtualFunc();

    Derived myDerived;

    myDerived.func1();
    myDerived.func2();
    myDerived.nonVirtualFunc();

    return 0;
}