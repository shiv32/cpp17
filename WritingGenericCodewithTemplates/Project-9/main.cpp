/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 *
    Limit Class Template Instantiations
    g++ -std=c++17 *.cpp -o test
 *
 *
 * @version 0.1
 * @date 2025-04-18
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include "grid.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    //------------- Allowed types -------------------------
    Grid<int> myIntGrid;
    myIntGrid.at(0, 0) = 10;

    Grid<double> myDoubleGrid;
    Grid<std::vector<int>> myVectorIntGrid;

    //------------- Not allowed types -------------------------
    // Grid<char> myCharGrid;  //Compilation error char not allowed
    // Grid<std::vector<double>> myVectorDoubleGrid;  //Compilation error std::vector<double> not allowed

    return 0;
}