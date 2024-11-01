/*
Method Templates with Non-type Parameters

g++ -std=c++17 main.cpp -o test
*/

#include <iostream>
#include "grid.hpp"

int main()
{
    Grid<int, 15, 15> intGrid;

    intGrid.at(5, 5) = 67;

    std::cout << intGrid.at(5, 5).value_or(0) << std::endl;

    Grid<double, 10, 10> doubleGrid(intGrid);

    std::cout << doubleGrid.at(5, 5).value_or(0) << std::endl;

    doubleGrid = intGrid;

    std::cout << doubleGrid.at(5, 5).value_or(0) << std::endl;

    return 0;
}