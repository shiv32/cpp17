/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief The Base Class Method Has a Different Access Level
 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include "Shy.hpp"
#include "Blabber.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Shy myShy;
    // myShy.talk(); // Error! Attempt to access protected method.

    // Shy myShy;
    // Gregarious &ref = myShy;
    // ref.talk();

    Blabber myBlabber;
    // myBlabber.tell();
    myBlabber.dontTell();

    // Blabber myBlabber;
    // Secret &ref = myBlabber;
    // Secret *ptr = &myBlabber;
    // ref.dontTell();  // Error! Attempt to access protected method.
    // ptr->dontTell(); // Error! Attempt to access protected method.

    return 0;
}