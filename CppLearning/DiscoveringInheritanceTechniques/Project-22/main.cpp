/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief A few restrictions apply to inheriting constructors from a base class with the using clause.
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

    //Derived d('j');
    Derived d(2.4f);

    return 0;
}