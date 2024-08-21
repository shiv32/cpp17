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

                eg.

                class Base
                {
                public:
                    virtual void func1() {}
                    virtual void func2() {}
                    void nonVirtualFunc() {}
                };

                class Derived : public Base
                {
                public:
                    virtual void func2() override {}
                    void nonVirtualFunc() {}
                };


                Two instances ->

                Base myBase;
                Derived myDerived;

                High-level view of how the vtables for both instances look ->

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



                The myBase object contains a pointer to its vtable. This vtable has two entries, one for func1() and
                one for func2().
                Those entries point to the implementations of Base::func1() and Base::func2().

                myDerived also contains a pointer to its vtable, which also has two entries, one for func1() and
                one for func2().
                Its func1() entry points to Base::func1() because Derived does not override func1().
                On the other hand, its func2() entry points to Derived::func2().

                Note that both vtables do not contain any entry for the nonVirtualFunc() method because that
                method is not virtual.

          The Justification for virtual
                To call a virtual method, the program needs to perform an extra operation by dereferencing the pointer
                to the appropriate code to execute.

                This is a miniscule performance hit in most cases.

                If the method was never going to be overridden, there was no need to make it virtual and
                take the performance hit.

                In most applications, you will not have a measurable performance difference between using virtual methods
                and avoiding them.
                So you should still follow the advice of making all methods, especially destructors, virtual.

                In certain cases, the performance overhead might be too costly.
                    eg.
                        Suppose you have a Point class that has a virtual method.
                        If you have another data structure that stores millions or even billions of Points,
                        calling a virtual method on each point creates a significant overhead.
                        In that case, it’s probably wise to avoid any virtual methods in your Point class.

                        There is also a tiny hit to memory usage for each object.
                        In addition to the implementation of the method, each object also needs a pointer for its vtable,
                        which takes up a tiny amount of space.
                        Sometimes it does matter. Take again the Point class and the container storing billions
                        of Points.
                        In that case, the additional required memory becomes significant.


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

  Base myBase;

  myBase.func1();
  myBase.func2();
  myBase.nonVirtualFunc();

  Derived myDerived;

  myDerived.func1();
  myDerived.func2();
  myDerived.nonVirtualFunc();

  return 0;
}