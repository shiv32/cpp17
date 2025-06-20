/*
    Assigning to Objects
    Explicitly Defaulted and Deleted Assignment Operator
    Compiler-Generated Copy Constructor and Copy Assignment Operator

    g++ -std=c++17 *.cpp -o test
*/

#include <iostream>
#include "SpreadsheetCell.hpp"

int main()
{
    //------------------------- case 1 -----------------------------------------
    SpreadsheetCell myCell(5), anotherCell, aThirdCell(10);
    // anotherCell = myCell;  //assignment

    //------------------------- case 2 -----------------------------------------
    // myCell = myCell; // Self-assignment

    //------------------------- case 3 -----------------------------------------
    myCell = anotherCell = aThirdCell;
    // or
    // myCell.operator=(anotherCell.operator=(aThirdCell));

    return 0;
}