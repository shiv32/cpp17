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

/*
    Here type is converted and grid size is also changed.
*/

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Grid<int> myIntGrid;
    // Grid<double> myDoubleGrid;

    // myDoubleGrid = myIntGrid;              // assignment, copy ctor called
    // Grid<double> newDoubleGrid(myIntGrid); // copy ctor called

    //--------------------------------------------------------------------------
    Grid<int> myIntGrid2(15, 15); // myIntGrid2 is 15X15
    myIntGrid2.at(14, 14) = 67;

    Grid<double> myDoubleGrid2(5, 5); // myDoubleGrid2 is 5X5

    std::cout << myDoubleGrid2.getHeight() << std::endl;
    std::cout << myDoubleGrid2.getWidth() << std::endl;

    myDoubleGrid2 = myIntGrid2; // myDoubleGrid2 is now 15X15

    std::cout << myDoubleGrid2.getHeight() << std::endl;
    std::cout << myDoubleGrid2.getWidth() << std::endl;

    std::cout << myDoubleGrid2.at(14, 14).value_or(0) << std::endl;

    //--------------------------------------------------------------------------
    // Grid<int> myIntGrid3(5, 5);
    // myIntGrid3.at(4, 4) = 68;

    // Grid<double> myDoubleGrid3(15, 15);  //myDoubleGrid3 is 15X15

    // myDoubleGrid3 = myIntGrid3;  //myDoubleGrid3 is now 5X5

    // std::cout << myDoubleGrid3.at(4, 4).value_or(0) << std::endl;

    //------------------------------------------------------------------------
    // Grid<int> myIntGrid4(5, 5);
    // myIntGrid4.at(4, 4) = 68;
    // Grid<double> myDoubleGrid4(15, 15);

    // std::cout << myDoubleGrid4.getHeight() << std::endl;
    // std::cout << myDoubleGrid4.getWidth() << std::endl;

    // myDoubleGrid4 = myIntGrid4;

    // std::cout << myDoubleGrid4.getHeight() << std::endl;
    // std::cout << myDoubleGrid4.getWidth() << std::endl;

    // std::cout << myDoubleGrid4.at(14, 14).value_or(0) << std::endl; //crash

    return 0;
}