/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 *
    User-defined deduction guide

    g++ -std=c++17 main.cpp -o test
 *
 *
 * @version 0.1
 * @date 2025-04-23
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include "spreadsheetcell.hpp"

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::string myString = "Hello World!";
    SpreadsheetCell cell(myString);
    std::cout << cell.getContent() << std::endl;

    SpreadsheetCell cell2("Hello World 2!"); // const char *
    std::cout << cell2.getContent() << std::endl;

    return 0;
}