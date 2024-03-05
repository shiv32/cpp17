/*
Non-type Template Parameters

g++ -std=c++17 main.cpp -o test
*/

#include <iostream>
#include "grid.hpp"

constexpr size_t getHeight()
{
    return 10;
}

int main()
{

    Grid<int, 10, 10> myGrid;

    Grid<int, 10, 10> anotherGrid;

    myGrid.at(2, 3) = 42;

    anotherGrid = myGrid;

    std::cout << anotherGrid.at(2, 3).value_or(0) << std::endl;

    //------------------
    const size_t height = 10;
    Grid<int, 10, height> testGrid; // Compiles and work
    testGrid.at(2, 3) = 43;
    std::cout << testGrid.at(2, 3).value_or(0) << std::endl;

    //---------------------
    Grid<double, 2, getHeight()> myDoubleGrid;
    myDoubleGrid.at(1, 3) = 44.5;
    std::cout << myDoubleGrid.at(1, 3).value_or(0) << std::endl;

    return 0;
}