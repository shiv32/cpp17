/*
    Copy Constructors and Object Members

    g++ -std=c++17 *.cpp -o test
*/

#include <iostream>
#include "SpreadsheetCell.hpp"

int main()
{
    SpreadsheetCell myCell(5);

    // Constructed with the copy constructor, because this is a declaration.
    // The operator= is not called for this line!
    SpreadsheetCell anotherCell(myCell);

    return 0;
}