/*

Object creation
    When an object is created, all its embedded objects are also created.
    Whenever an object is created, one of its constructors is executed.
    C++ programmers sometimes call a constructor a ctor.

    g++ -std=c++17 *.cpp -o test

*/

#include <iostream>
#include "MyClass.hpp"

int main()
{
    MyClass obj;
    return 0;
}
