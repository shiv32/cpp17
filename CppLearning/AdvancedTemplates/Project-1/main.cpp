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

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    Grid<int, std::vector<std::optional<int>>> myIntVectorGrid;
    Grid<int, std::deque<std::optional<int>>> myIntDequeGrid;

    myIntVectorGrid.at(3, 4) = 5;
    std::cout << myIntVectorGrid.at(3, 4).value_or(0) << std::endl;

    myIntDequeGrid.at(1, 2) = 3;
    std::cout << myIntDequeGrid.at(1, 2).value_or(0) << std::endl;

    Grid<int, std::vector<std::optional<int>>> grid2(myIntVectorGrid);
    grid2 = myIntVectorGrid;

    //Grid<int, int> test; // WILL NOT COMPILE

    //----------
    Grid<int, std::deque<std::optional<int>>> myDequeGrid;
    Grid<int, std::vector<std::optional<int>>> myVectorGrid;
    myVectorGrid.at(3, 4) = 59;

    Grid<int> myVectorGrid2(myVectorGrid); // template parameters default values
    std::cout << myVectorGrid2.at(3, 4).value_or(0) << std::endl;

    return 0;
}