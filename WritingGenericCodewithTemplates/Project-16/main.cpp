/*
Class Template Specialization

g++ -std=c++17 main.cpp -o test
*/

#include <iostream>
#include "grid.hpp"

int main()
{
    Grid<int> myIntGrid; // Uses original Grid template
    myIntGrid.at(0, 0) = 10;

    Grid<const char *> stringGrid1(2, 2); // Uses const char* specialization

    const char *dummy = "dummy";

    stringGrid1.at(0, 0) = "hello";
    stringGrid1.at(0, 1) = dummy;
    stringGrid1.at(1, 0) = dummy;
    stringGrid1.at(1, 1) = "there";

    Grid<const char *> stringGrid2(stringGrid1);

    return 0;
}