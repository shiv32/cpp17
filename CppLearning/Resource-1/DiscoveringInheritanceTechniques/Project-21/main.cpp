/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Inherited Constructors
 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include "Base.hpp"
#include "Derived.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    //     Base base("Hello");  // OK, calls string_view Base ctor
    //     Derived derived1(1); // OK, calls integer Derived ctor
    //    // Derived derived2("Hello"); // Error, Derived does not inherit string_view ctor

    // Derived derived1(1);       // OK, calls integer Derived ctor
    // Derived derived2("Hello"); // using Base::Base;
    //                            // OK, calls inherited string_view Base ctor

    Derived derived1("Hello"); // OK, calls inherited string_view Base ctor
    Derived derived2(1.23f);   // OK, calls float Derived ctor

    return 0;
}