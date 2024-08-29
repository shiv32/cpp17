/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief  Parent Destructors
                Because destructors cannot take arguments, the language can always automatically call the
                destructor for parent classes. 
                
                The order of destruction is conveniently the reverse of the order of construction:

                1. The body of the class’s destructor is called.

                2. Any data members of the class are destroyed in the reverse order of their construction.

                3. The parent class, if any, is destructed.
          
                Again, these rules apply recursively. 

                The lowest member of the chain is always destructed first. 

                The destructors are all declared virtual!

                WARNING:    Always make your destructors virtual! The compiler-generated
                            default destructor is not virtual, so you should define (or explicitly default) a
                            virtual destructor, at least for your parent classes.

                WARNING:    Just as with constructors, virtual methods behave differently when
                            called from a destructor. If your derived class has overridden a virtual method
                            from the base class, calling that method from the base class destructor calls the
                            base class implementation of that virtual method and not your overridden version in
                            the derived class.

 * @version 0.1
 * @date 2024-08-28
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


    std::cout << "-------------(Destructors start)------------------" << std::endl;

    return 0;
}