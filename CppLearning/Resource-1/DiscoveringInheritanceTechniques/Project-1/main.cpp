/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief BUILDING CLASSES WITH INHERITANCE             
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
    
    Derived myDerived;
    myDerived.someMethod();
    myDerived.someOtherMethod();

    /*
    Base myBase;
    myBase.someOtherMethod(); // Error! Base doesn't have a someOtherMethod().
    */

   //Base* base = new Derived(); // Create Derived, store it in Base pointer.
   //base->someOtherMethod(); // Error! 
   //base->someMethod();

    return 0;
}