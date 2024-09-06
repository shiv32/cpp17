/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Casting Up and Down
            An object can be cast or assigned to its parent class.
            If the cast or assignment is performed on a plain old object, this results in slicing.

            Base myBase = myDerived; // Slicing!

            Slicing occurs because the end result is a Base object, and
            Base objects lack the additional functionality defined in the Derived class. 

            Slicing does not occur if a derived class is assigned to a pointer or reference to its base class.

            Base& myBase = myDerived; // No slicing!

            This is generally the correct way to refer to a derived class in terms of its base class, 
            also called upcasting. 

            WARNING:    When upcasting, use a pointer or reference to the base class to avoid
                        slicing.

            Casting from a base class to one of its derived classes, also called downcasting,
            is often frowned upon by professional C++ programmers because there is no guarantee that
            the object really belongs to that derived class.
            Downcasting is a sign of bad design.

            eg.
                    void presumptuous(Base* base)
                        {
                            Derived* myDerived = static_cast<Derived*>(base);
                            // Proceed to access Derived methods on myDerived.
                        }
                    
            If the author of presumptuous() also writes code that calls presumptuous(), everything will
            probably be okay because the author knows that the function expects the argument to be of type
            Derived*.

            if other programmers call presumptuous(), they might pass in a Base*. 
            There are no compile-time checks that can be done to enforce the type of the argument, and
            the function blindly assumes that base is actually a pointer to a Derived.

            Downcasting is sometimes necessary, and you can use it effectively in controlled circumstances.

            However, if you are going to downcast, you should use a dynamic_cast(), which uses the object’s
            built-in knowledge of its type to refuse a cast that doesn’t make sense.

            This built-in knowledge typically resides in the vtable, which means that dynamic_cast() works only for objects 
            with a vtable, that is, objects with at least one virtual member. 

            If a dynamic_cast() fails on a pointer, the pointer’s value will be nullptr instead of pointing to nonsensical data.

            If a dynamic_cast() fails on an object reference, an std::bad_cast exception will be thrown. 

            eg.
                void lessPresumptuous(Base* base)
                    {
                        Derived* myDerived = dynamic_cast<Derived*>(base);

                        if (myDerived != nullptr) 
                        {
                            // Proceed to access Derived methods on myDerived.
                        }
                    }

            You should rethink and modify your design so that downcasting can be avoided. 

            For example, the lessPresumptuous() function only really works with Derived objects, 
            so instead of accepting a Base pointer, it should simply accept a Derived pointer. 

            This eliminates the need for any downcasting. 
            If the function should work with different derived classes, all inheriting from Base, 
            then look for a solution that uses polymorphism.

            WARNING:    Use downcasting only when really necessary, and be sure to use a
                        dynamic_cast().

 * @version 0.1
 * @date 2024-09-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    return 0;
}