/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief When using inherited constructors, make sure that all member variables are properly initialized.
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

    //Derived s1(2);
    Derived s2("Hello World"); 

    return 0;
}