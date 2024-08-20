/**
 * @file main.cpp
 * @author your name (you@domain.com)
 *
 * @brief How virtual Is Implemented
 *              When a class is compiled in C++, a binary object is created that contains
                all methods for the class. 
                In the non-virtual case, the code to transfer control to the appropriate
                method is hard-coded directly where the method is called based on the compile-time type. 
                This is called static binding, also known as early binding.

                If the method is declared virtual, the correct implementation is called through the use of a 
                special area of memory called the vtable, or “virtual table.” 

                Each class that has one or more virtual methods, has a vtable, and every object of such a class contains a 
                pointer to said vtable. 
                This vtable contains pointers to the implementations of the virtual methods.
                when a method is called on an object, the pointer is followed into the vtable and the appropriate version 
                of the method is executed based on the actual type of the object at run time.
                This is called dynamic binding, also known as late binding.


                myBase
                vtable -->    func1 --> Base::func1()
                                        Implementation
                              
                              func2 --> Base::func2()
                                        Implementation

                myDerived
                vtable -->    func1 --> Base::func1()
                                        Implementation
                              
                              func2 --> Derived::func2()
                                        Implementation

            


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