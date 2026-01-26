#include <iostream>
#include "SpreadsheetCell.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

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