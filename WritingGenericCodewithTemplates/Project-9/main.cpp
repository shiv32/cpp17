/*
Limit Class Template Instantiations

g++ -std=c++17 *.cpp -o test
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