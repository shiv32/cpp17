/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Overriding Methods
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

    Base myBase;
    myBase.someMethod(); // Calls Base's version of someMethod().

    Derived myDerived;
    myDerived.someMethod(); // Calls Derived's version of someMethod()

    /*
    This aspect of overriding does not work properly if you omit the virtual
    keyword in the base class.
    */
    Base &ref = myDerived;
    ref.someMethod(); // Calls Derived's version of someMethod()

    /*
    Remember that even though a base class reference or pointer knows that it is actually a derived
    class, you cannot access derived class methods or members that are not defined in the base class.
    */
    Base &ref2 = myDerived;
    myDerived.someOtherMethod(); // This is fine.
    // ref2.someOtherMethod();      // Error

    /*
    The derived class knowledge characteristic is not true for non-pointer or non-reference objects. You
    can cast or assign a Derived to a Base because a Derived is a Base. However, the object loses any
    knowledge of the derived class at that point.

    NOTE:   Derived classes retain their overridden methods when referred to by base
            class pointers or references. 
            They lose their uniqueness when cast to a base class object. 
            The loss of the derived class’s data members and overridden methods is called slicing.
    */
    Base assignedObject = myDerived; // Assigns a Derived to a Base.
    assignedObject.someMethod();     // Calls Base's version of someMethod()

    return 0;
}