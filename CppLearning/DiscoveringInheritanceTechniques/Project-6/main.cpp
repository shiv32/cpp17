/**
 * @file main.cpp
 * @author your name (you@domain.com)
 *
 * @brief The Need for virtual Destructors
                Making your destructors non-virtual can easily result in situations in which memory is not 
                freed by object destruction. 
                Only for a class that is marked as final you could make its destructor non-virtual.

                NOTE:   If you don’t need to do any work in your destructor, but you only want
                        to make it virtual, you can explicitly default it. For example:
                            
                            class Base
                            {
                            public:
                            virtual ~Base() = default;
                            };

                WARNING: Unless you have a specific reason not to, or the class is marked as
                        final, I recommend making all methods, including destructors but not 
                        constructors, virtual. 
                        Constructors cannot and need not be virtual because you
                        always specify the exact class being constructed when creating an object.

                Preventing Overriding
                    C++ allows you to mark a method as final, which means that the method cannot 
                    be overridden in a derived class. Trying to override a final method results in
                    a compilation error.
 


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

    Base *ptr = new Derived(); // mString is allocated here.

    delete ptr;                // ~Base is called, but not ~Derived because the destructor
                              // is not virtual!

    return 0;
}