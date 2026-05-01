/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief The override Keyword
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
    Base &ref = myDerived;
    ref.someMethod(1.1); // Calls Derived's version of someMethod()
                          // Calls Base's version of someMethod() for "virtual void someMethod(int i);""

    return 0;
}