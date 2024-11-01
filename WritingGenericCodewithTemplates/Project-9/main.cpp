/*
Limit Class Template Instantiations

g++ -std=c++17 *.cpp -o test
*/

#include <iostream>
#include "grid.hpp"

int main()
{

    Grid<int> myIntGrid; 
    myIntGrid.at(0, 0) = 10;

    return 0;
}