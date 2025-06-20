/*
    FRIENDS
*/

#include <iostream>

#include "Bar.hpp"
#include "Foo.hpp"
#include "Bar2.hpp"

int main()
{
    Foo fo{"shiv kumar"};
    Bar br;
    Bar2 br2;

    br.displayClassFooData(fo); // Bar class is a friend of Foo class.

    br2.ProcessFoo(fo); // Bar2 class method make friend of Foo class.

    dumpFoo(fo); // Standalone function make friend of Foo class.

    return 0;
}