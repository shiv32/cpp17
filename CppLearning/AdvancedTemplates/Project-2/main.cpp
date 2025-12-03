/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 *
    g++ -std=c++17 *.cpp -o test
 *
 * @version 0.1
 * @date 2025-03-29
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include "grid.hpp"

class SpreadsheetCell
{
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Grid<int, std::vector<std::optional<SpreadsheetCell>>> myTestGrid;
    // myTestGrid.at(3, 4) = 5;// mismatched types compile time error

    Grid<int, std::vector> myGrid;

    myGrid.at(1, 2) = 3;

    std::cout << myGrid.at(1, 2).value_or(0) << std::endl;

    Grid<int, std::vector> myGrid2(myGrid);

    return 0;
}