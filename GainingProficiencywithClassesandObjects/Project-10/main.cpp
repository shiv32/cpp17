/*

Constructors on the Stack

g++ -std=c++17 *.cpp -o test

*/

#include <iostream>
#include <memory>
#include "SpreadsheetCell.hpp"

int main()
{
    SpreadsheetCell myCell(5), anotherCell(4);
    std::cout << "cell 1: " << myCell.getValue() << std::endl;
    std::cout << "cell 2: " << anotherCell.getValue() << std::endl;

    return 0;
}