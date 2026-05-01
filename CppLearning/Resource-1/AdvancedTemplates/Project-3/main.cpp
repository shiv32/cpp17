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

struct SpreadsheetCell
{
    float value_{};
    SpreadsheetCell(float value) : value_(value) {};
    float getValue() { return value_; };
};

// pre-C++17 rules, The initial values are defined with internal linkage
namespace
{
    int defaultInt = 11;
    SpreadsheetCell defaultCell(1.2);
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // using namespace GridV1;

    // Grid<int> myIntGrid;      // Initial value is 0
    // Grid<int, 10> myIntGrid2; // Initial value is 10

    // std::cout << myIntGrid.at(1, 2).value_or(0) << std::endl;
    // std::cout << myIntGrid2.at(1, 2).value_or(0) << std::endl;

    //-------------------------------------
    // SpreadsheetCell defaultCell;
    // Grid<SpreadsheetCell, defaultCell> mySpreadsheet; // WILL NOT COMPILE in C++17 Compiler, in C++20 its work

    //---------------------------
    using namespace GridV2;

    // int defaultInt = 11; //C++17, most compilers do not implement those rules yet.
    Grid<int, defaultInt> myIntGrid;

    // SpreadsheetCell defaultCell(1.2); //C++17, most compilers do not implement those rules yet.
    // Grid<SpreadsheetCell, defaultCell> mySpreadsheet;
    Grid<SpreadsheetCell, defaultCell> mySpreadsheet(3, 3); // 3X3 grid

    std::cout << myIntGrid.at(1, 2).value_or(0) << std::endl;
    std::cout << mySpreadsheet.at(1, 2).value_or(SpreadsheetCell(0.0)).getValue() << std::endl;

    return 0;
}