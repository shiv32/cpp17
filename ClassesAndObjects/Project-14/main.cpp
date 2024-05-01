/*

Compiler-Generated Default Constructor

g++ -std=c++17 *.cpp -o test

*/

#include <iostream>
#include "SpreadsheetCell.hpp"

int main()
{
    SpreadsheetCell myCell;
    myCell.setValue(16);

    std::cout << "cell 1 : " << myCell.getValue() << std::endl;

    return 0;
}