/*
Constructor Initializers part 1

g++ -std=c++17 *.cpp -o test
*/

#include <iostream>
#include "SpreadsheetCell.hpp"

int main()
{
    SpreadsheetCell myCell(61.8);

    std::cout << "cell 1: " << myCell.getValue() << std::endl;

    return 0;
}