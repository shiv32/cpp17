/**
 * @file main.cpp
 * @author your name (you@domain.com)
 *
 * @brief BUILDING CLASSES WITH INHERITANCE
 *          Extending Classes
 *              When you write a class definition in C++, you can tell the compiler that your class is
 *              inheriting from, deriving from, or extending an existing class.

                By doing so, your class automatically contains the data members and methods of the original class,
                which is called the parent class or base class or superclass.

                Extending an existing class gives your class (which is now called a derived class or a sub-
                class) the ability to describe only the ways in which it is different from the parent class.

                To show the syntax for inheritance, two classes are used, called Base and Derived.

                Simple relationship between Derived and Base :

                    Base <- Derived

                You could even define a third class that inherits from Derived, forming a chain of classes :

                    Base <- Derived <- DerivedDerived

                Derived doesn’t have to be the only derived class of Base.
                Additional classes can also inherit from Base, effectively becoming siblings to Derived.

                    Base <- Derived1
                    Base <- Derived2

                A Client’s View of Inheritance
                    An object of type Derived is also an object of type Base because Derived inherits from Base.
                        All the public methods and data members of Base and all the public methods and data members 
                        of Derived are available.
                    
                    It is important to understand that inheritance works in only one direction. 
                    The Derived class has a very clearly defined relationship to the Base class, 
                    but the Base class, as written, doesn’t know anything about the Derived class. 
                    That means that objects of type Base do not support public methods and data members of Derived 
                    because Base is not a Derived.

                    Note: From the perspective of other code, an object belongs to its defined class
                          as well as to any base classes.
                    




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

   //A Client’s View of Inheritance

    Derived myDerived;
    myDerived.someMethod();
    myDerived.someOtherMethod();

    /*
    Base myBase;
    myBase.someOtherMethod(); // Error! Base doesn't have a someOtherMethod().
    */

   //Base* base = new Derived(); // Create Derived, store it in Base pointer.
   //base->someOtherMethod(); // Error! 

   //A Derived Class’s View of Inheritance

    return 0;
}