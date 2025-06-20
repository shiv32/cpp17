/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief  Method templates

           g++ -std=c++17 main.cpp -o test

 * @version 0.1
 * @date 2025-05-17
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
    Grid<double> myDoubleGrid;

    myDoubleGrid = myIntGrid; //assignment, copy ctor called
    
    Grid<double> newDoubleGrid(myIntGrid); //copy ctor called

    return 0;
}