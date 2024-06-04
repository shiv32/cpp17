/*
    FRIENDS
*/

#include <iostream>

#include "Bar.hpp"
#include "Foo.hpp"

int main()
{
    Bar br;
    Foo fo{"shiv kumar"};
    Bar2 br2;

    br.displayClassFooData(fo);

    br2.ProcessFoo(fo);

    return 0;
}