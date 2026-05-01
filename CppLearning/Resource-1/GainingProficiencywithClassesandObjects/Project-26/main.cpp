#include <iostream>
#include "SpreadsheetCell.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    SpreadsheetCell myCell(5);

    // Constructed with the copy constructor, because this is a declaration.
    // The operator= is not called for this line!
    SpreadsheetCell anotherCell(myCell);

    SpreadsheetCell aThirdCell = myCell;
    // or
    // SpreadsheetCell aThirdCell(myCell);

    //-----------------------------------------------------------------------------------
    anotherCell = myCell; // Calls operator= for anotherCell
                          // anotherCell has already been constructed, so the compiler calls operator=

    return 0;
}