/**
 * @file main.cpp
 * @author your name (you@domain.com)
 *
 * @brief The Truth about virtual
            If a method is not virtual, you can still attempt to override it, but it will be wrong in subtle ways.

          Hiding Instead of Overriding
            The derived class is attempting to override the method in the base class, but it is not declared to be virtual
            in the base class.

            The method is not virtual, it is not actually overridden.
            Rather, the Derived class creates a new method, also called go(),
            that is completely unrelated to the Base class’s method called go().

            class Base
            {
            public:
            void go() { cout << "go() called on Base" << endl; }
            };

            class Derived : public Base
            {
            public:
            void go() { cout << "go() called on Derived" << endl; }
            }

            WARNING:  Attempting to override a non-virtual method hides the base class
                      definition, and it will only be used in the context of the derived class.


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
    myDerived.go();

    
    Base &ref = myDerived;
    ref.go();

    return 0;
}