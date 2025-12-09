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
// #include "grid.hpp"
// #include "gridPsV1.hpp"
#include "gridPsV2.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Grid<int, 2, 2> myIntGrid; // Uses the original Grid
    // Grid<const char *, 2, 2> myStringGrid; // Uses the partial specialization
    // //Grid<2, 3> test; // DOES NOT COMPILE! No type specified.

    //--------------
    Grid<int> myIntGrid;      // Uses the non-specialized grid
    Grid<int *> psGrid(2, 2); // Uses the partial specialization for pointer types

    psGrid.at(0, 0) = std::make_unique<int>(1);
    psGrid.at(0, 1) = std::make_unique<int>(2);
    psGrid.at(1, 0) = std::make_unique<int>(3);

    Grid<int *> psGrid2(psGrid);
    Grid<int *> psGrid3;
    psGrid3 = psGrid2;

    auto &element = psGrid2.at(1, 0);

    if (element)
    {
        std::cout << *element << std::endl;
        *element = 6;
    }

    std::cout << *psGrid.at(1, 0) << std::endl;  // psGrid is not modified
    std::cout << *psGrid2.at(1, 0) << std::endl; // psGrid2 is modified

    return 0;
}