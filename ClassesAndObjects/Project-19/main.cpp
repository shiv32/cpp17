/*
Copy Constructors
Calling the Copy Constructor Explicitly

g++ -std=c++17 *.cpp -o test
*/

#include <iostream>
#include "SpreadsheetCell.hpp"

int main()
{
    SpreadsheetCell myCell(61.8);
    SpreadsheetCell myCell2(myCell); // myCell2 has the same values as myCell

    std::cout<<myCell2.getValue()<<std::endl;

    return 0;
}