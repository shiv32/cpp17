/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 *
    Template Definitions in Header Files

    g++ -std=c++17 *.cpp -o test
 *
 * @version 0.1
 * @date 2025-04-05
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include "grid.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    Grid<int> myIntGrid;
    myIntGrid.at(0, 0) = 10;

    return 0;
}