/*
Delegating Constructors
Delegating constructors allow constructors to call another constructor from the same class.

g++ -std=c++17 *.cpp -o test
*/

#include <iostream>
#include "SpreadsheetCell.hpp"

int main()
{
    SpreadsheetCell myCell("61.8");
    std::cout << myCell.getValue() << std::endl;

    return 0;
}