/*
    DYNAMIC MEMORY ALLOCATION IN OBJECTS
    Freeing Memory with Destructors
*/

#include <iostream>
#include "Spreadsheet.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    Spreadsheet s1(4, 3);

    SpreadsheetCell sc1(5.66);
    SpreadsheetCell sc2(8.98);

    s1.setCellAt(2, 1, sc1);
    s1.setCellAt(2, 0, sc2);

    std::cout << "Cell value at (2,1): " << s1.getCellAt(2, 1).getValue() << std::endl;
    std::cout << "Cell value at (2,0): " << s1.getCellAt(2, 0).getValue() << std::endl;

    return 0;
}