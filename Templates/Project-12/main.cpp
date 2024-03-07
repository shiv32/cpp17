/*
Template parameter deduction for constructors

g++ -std=c++17 main.cpp -o test
*/

#include <iostream>
#include "grid.hpp"

int main()
{
    Grid defaultGrid(10);

    defaultGrid.at(5, 5) = 67.6;

    std::cout << defaultGrid.at(5, 5).value_or(0) << std::endl;

    Grid defaultGrid2(10.5);

    defaultGrid2.at(3, 5) = 67.6;

    std::cout << defaultGrid2.at(3, 5).value_or(0) << std::endl;

    return 0;
}