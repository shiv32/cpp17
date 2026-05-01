/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * 
    Selective Instantiation
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

using IntGrid = Grid<int>;

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

     Grid<int> myIntGrid;
     myIntGrid.at(0, 0) = 10;

    return 0;
}