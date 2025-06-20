/**
 * @file main.cpp
 * @author your name (you@domain.com)
 *
 * @brief The override Keyword
 *              Sometimes, it is possible to accidentally create a new virtual method instead of overriding a
                method from the base class.

             eg.
                In Base and Derived classes where Derived is properly overriding someMethod(),
                but is not using the override keyword.
                This correctly calls the overridden someMethod() from the Derived class.

                virtual void someMethod(double d);

                suppose you accidentally use an integer parameter instead of a double while overriding someMethod().

                virtual void someMethod(int i);

                This code does not override someMethod() from Base, but instead creates a new virtual method.

                Derived myDerived;
                Base& ref = myDerived;
                ref.someMethod(1.1); // Calls Base's version of someMethod()

                You can prevent this situation by using the override keyword.

                class Derived : public Base
                {
                public:
                virtual void someMethod(int i) override;
                };

                This definition of Derived generates a compilation error, because with the override keyword you
                are saying that someMethod() is supposed to be overriding a method from a base class, but in the
                Base class there is no someMethod() accepting an integer, only one accepting a double.

                NOTE: Always use the override keyword on methods that are meant to be overriding methods
                      from a base class.

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
    Base &ref = myDerived;
    ref.someMethod(1.1); // Calls Derived's version of someMethod()
                          // Calls Base's version of someMethod() for "virtual void someMethod(int i);""

    return 0;
}