/*
 Method templates
 useful for assignment operators and copy constructors in class templates.

g++ -std=c++17 main.cpp -o test
*/

#include <iostream>
#include "grid.hpp"

int main()
{
    Grid<int> myIntGrid;
    Grid<double> myDoubleGrid;

    myDoubleGrid = myIntGrid;
    Grid<double> newDoubleGrid(myIntGrid);

    return 0;
}