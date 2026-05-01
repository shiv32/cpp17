/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 *
    Class Template Specialization

    g++ -std=c++17 main.cpp -o test
 *
 *
 * @version 0.1
 * @date 2025-05-22
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include "grid.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    Grid<int> myIntGrid; // Uses original Grid template
    myIntGrid.at(0, 0) = 10;

    std::cout << "myIntGrid Value at (0,0) : " << myIntGrid.at(0, 0).value_or(0) << std::endl;

    Grid<const char *> stringGrid1(2, 2); // Uses const char* specialization

    const char *dummy = "dummy";

    stringGrid1.at(0, 0) = "hello";
    stringGrid1.at(0, 1) = dummy;
    stringGrid1.at(1, 0) = dummy;
    stringGrid1.at(1, 1) = "there";

    Grid<const char *> stringGrid2(stringGrid1);

    std::cout << "stringGrid1 Value at (0,0) : " << stringGrid1.at(0, 0).value_or("") << std::endl;
    std::cout << "stringGrid1 Value at (0,1) : " << stringGrid1.at(0, 1).value_or("") << std::endl;
    std::cout << "stringGrid1 Value at (1,0) : " << stringGrid1.at(1, 0).value_or("") << std::endl;
    std::cout << "stringGrid1 Value at (1,1) : " << stringGrid1.at(1, 1).value_or("") << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "stringGrid2 Value at (0,0) : " << stringGrid2.at(0, 0).value_or("") << std::endl;
    std::cout << "stringGrid2 Value at (0,1) : " << stringGrid2.at(0, 1).value_or("") << std::endl;
    std::cout << "stringGrid2 Value at (1,0) : " << stringGrid2.at(1, 0).value_or("") << std::endl;
    std::cout << "stringGrid2 Value at (1,1) : " << stringGrid2.at(1, 1).value_or("") << std::endl;

    return 0;
}