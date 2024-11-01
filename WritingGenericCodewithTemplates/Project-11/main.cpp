/*
Default Values for Type Parameters

g++ -std=c++17 main.cpp -o test
*/

#include <iostream>
#include "grid.hpp"

int main()
{

    Grid<> defaultGrid;

    defaultGrid.at(5, 5) = 67;

    Grid<int> defaultWHGrid;

    defaultWHGrid.at(5, 5) = 68;

    Grid<int, 10> myGrid;

    Grid<int, 10, 10> anotherGrid;

    myGrid.at(2, 3) = 42;

    anotherGrid = myGrid;

    std::cout << anotherGrid.at(2, 3).value_or(0) << std::endl;

    std::cout << defaultGrid.at(5, 5).value_or(0) << std::endl;

    std::cout << defaultWHGrid.at(5, 5).value_or(0) << std::endl;

    Grid<double, 20, 20> doubleGrid;

    doubleGrid.at(5, 5) = 44.8;

    std::cout << doubleGrid.at(5, 5).value_or(0) << std::endl;

    return 0;
}