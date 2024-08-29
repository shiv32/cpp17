/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief  RESPECT YOUR PARENTS
                You need to be aware of the interaction between parent classes and
                child classes. 

                Issues such as order of creation, constructor chaining, and casting are all potential
                sources of bugs.

            Parent Constructors
                Objects don’t spring to life all at once.

                They must be constructed along with their parents and any
                objects that are contained within them. 

                C++ defines the creation order as follows:

                1.  If the class has a base class, the default constructor of the base class is executed, unless there
                    is a call to a base class constructor in the ctor-initializer, in which case that constructor is
                    called instead of the default constructor.

                2.  Non-static data members of the class are constructed in the order in which they are
                    declared.

                3.  The body of the class’s constructor is executed.

                These rules can apply recursively. 

                If the class has a grandparent, the grandparent is initialized before the parent, and so on.

                C++ automatically calls the default constructor for the parent class if one exists. 

                If no default constructor exists in the parent class, or if one does exist but you want to use an 
                alternate constructor, you can chain the constructor just as when initializing data members in the 
                constructor initializer. 

                Passing constructor arguments from the derived class to the base class is perfectly fine and quite 
                normal. 

                Passing data members, however, will not work. 

                The code will compile, but remember that data members are not initialized until after the base class 
                is constructed. 

                If you pass a data member as an argument to the parent constructor, it will be uninitialized.

                WARNING:    Virtual methods behave differently in constructors. 
                            If your derived class has overridden a virtual method from the base class, 
                            calling that method from a base class constructor calls the base class implementation 
                            of that virtual method and not your overridden version in the derived class!

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

    return 0;
}