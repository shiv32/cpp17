/*
    Explicitly Deleting Overloads
        Overloaded methods can be explicitly deleted, which enables you to disallow calling a method with
        particular arguments.

        eg. In MyClass, the compiler converts the double value (1.23) to an integer value (1) and then
            calls foo(int i).
            You can prevent the compiler from performing this conversion by explicitly deleting a double
            instance of foo().

             void foo(double d) = delete;

*/

#include "MyClass.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    MyClass c;

    c.foo(123);
    // c.foo(1.23); //compiler error 

    return 0;
}