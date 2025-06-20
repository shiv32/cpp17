/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief The Base Class Method Has Default Arguments
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

    Base myBase;
    Derived myDerived;
    Base &myBaseReferenceToDerived = myDerived;
    
    myBase.go();
    myDerived.go();
    myBaseReferenceToDerived.go();

    return 0;
}