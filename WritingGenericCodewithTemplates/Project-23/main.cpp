/*
Friend Function Templates of Class Templates

g++ -std=c++17 main.cpp -o test
*/

#include <iostream>
#include "grid.hpp"

int main()
{
    Grid<int> myInt(8, 8);
    Grid<int> myInt2(8, 8);
    Grid<int> myInt3(8, 8);

    myInt.at(0, 0) = 2;
    myInt2.at(0, 0) = 3;

    myInt3 = myInt + myInt2;

    std::cout << "myInt3 (0,0) : " << myInt3.at(0, 0).value_or(0) << std::endl;

    return 0;
}