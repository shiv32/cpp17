/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief INTERESTING AND OBSCURE INHERITANCE ISSUES
            Changing the Overridden Method’s Characteristics
                Changing the Method Parameters
                    If you use the name of a virtual method from the parent class in the definition of a
                    derived class,but it uses different parameters than the method with that name uses in
                    the parent class, it is not overriding the method of the parent class—it is creating
                    a new method.

                        eg.
                            class Base
                            {
                                public:
                                virtual void someMethod();
                            };

                            class Derived : public Base
                            {
                                public:
                                virtual void someMethod(int i); // Compiles, but doesn't override
                                virtual void someOtherMethod();
                            };

                            The implementation of this method could be as follows:

                            void Derived::someMethod(int i)
                            {
                                cout << "This is Derived's version of someMethod with argument " << i
                                << "." << endl;
                            }

                            The preceding class definition compiles, but you have not overridden someMethod().
                            If you want a method called someMethod() that takes an int, and you want it to work
                            only on objects of class Derived, the preceding code is correct.

                            following sample code does not compile because there is no longer a no-argument version
                            of someMethod().

                                Derived myDerived;
                                myDerived.someMethod(); // Error! Won't compile because original method is hidden.


                            If your intention is to override someMethod() from Base, then you should use the override
                            keyword.
                            The compiler then gives an error if you make a mistake in overriding the method.

                            There is a somewhat obscure technique you can use to have your cake and eat it too.
                            That is, you can use this technique to effectively “override” a method in the
                            derived class with a new prototype but continue to inherit the base class version.

                            This technique uses the using keyword to explicitly include the base class definition
                            of the method within the derived class.

                                eg.

                                    class Base
                                    {
                                        public:
                                        virtual void someMethod();
                                    };

                                    class Derived : public Base
                                    {
                                        public:
                                        using Base::someMethod; // Explicitly "inherits" the Base version
                                        virtual void someMethod(int i); // Adds a new version of someMethod
                                        virtual void someOtherMethod();
                                    };

                            NOTE:   It is rare to find a method in a derived class with the same name
                                    as a method in the base class but using a different parameter list.



 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Derived.hpp"

#include <iostream>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    Derived myDerived;
    myDerived.someMethod(30);

    // myDerived.someMethod(); // Error! Won't compile because original method is hidden.

    /*
        Explicitly "inherits" the Base version
        using Base::someMethod;
    */
    myDerived.someMethod();

    return 0;
}