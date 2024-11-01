/*
Selective Instantiation

g++ -std=c++17 *.cpp -o test
*/

#include <iostream>
#include "grid.hpp"


using IntGrid = Grid<int>;

int main()
{

    Grid<int> myIntGrid; 
    myIntGrid.at(0, 0) = 10;

    return 0;
}