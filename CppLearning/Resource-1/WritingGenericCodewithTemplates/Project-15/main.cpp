/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 *
    Method Templates with Non-type Parameters

    g++ -std=c++17 main.cpp -o test
 *
 * @version 0.1
 * @date 2025-05-22
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include "grid.hpp"

/*
    Here type is converted but grid size is same.
*/

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    Grid<int, 15, 15> intGrid; // intGrid is 15X15
    intGrid.at(5, 5) = 67;
    intGrid.at(14, 14) = 69;
    std::cout << intGrid.at(5, 5).value_or(0) << std::endl;

    Grid<double, 10, 10> doubleGrid(intGrid); // doubleGrid is 10X10

    std::cout << doubleGrid.getHeight() << std::endl;
    std::cout << doubleGrid.getWidth() << std::endl;

    std::cout << doubleGrid.at(5, 5).value_or(0) << std::endl;

    doubleGrid = intGrid;

    std::cout << doubleGrid.getHeight() << std::endl;
    std::cout << doubleGrid.getWidth() << std::endl;

    std::cout << doubleGrid.at(5, 5).value_or(0) << std::endl;
    // std::cout << doubleGrid.at(14, 14).value_or(0) << std::endl; //crash

    //-------------------------
    try
    {
        Grid<int, 4, 4> intGrid2; // intGrid2 is 4X4
        intGrid2.at(3, 3) = 68;

        Grid<double, 15, 15> doubleGrid2(intGrid2); // doubleGrid2 is 15X15

        std::cout << doubleGrid2.at(3, 3).value_or(0) << std::endl;
        std::cout << doubleGrid2.at(5, 5).value_or(0) << std::endl;
        std::cout << doubleGrid2.at(14, 14).value_or(0) << std::endl;
        // std::cout << doubleGrid2.at(15, 15).value_or(0) << std::endl; //crash
    }
    catch (const std::exception &e)
    {
        std::cerr << "exception : " << e.what() << '\n';
    }

    return 0;
}