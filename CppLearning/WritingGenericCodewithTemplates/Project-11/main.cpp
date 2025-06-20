/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 *
    Default Values for Type Parameters

    g++ -std=c++17 main.cpp -o test
 *
 *
 * @version 0.1
 * @date 2025-04-19
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include "grid.hpp"

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    Grid<> defaultGrid;
    defaultGrid.at(5, 5) = 67;

    Grid<int> defaultWHGrid;
    defaultWHGrid.at(5, 5) = 68;

    Grid<int, 10> myGrid;
    Grid<int, 10, 10> anotherGrid;

    myGrid.at(2, 3) = 42;
    anotherGrid = myGrid;

    Grid<double, 20, 20> doubleGrid;
    doubleGrid.at(5, 5) = 44.8;

    Grid<double, 20, 20> anotherDoubleGrid;

    std::cout << defaultGrid.at(5, 5).value_or(0) << std::endl;
    std::cout << defaultWHGrid.at(5, 5).value_or(0) << std::endl;
    std::cout << anotherGrid.at(2, 3).value_or(0) << std::endl;
    std::cout << doubleGrid.at(5, 5).value_or(0) << std::endl;
    std::cout << anotherDoubleGrid.at(5, 5).value_or(0) << std::endl;

    return 0;
}