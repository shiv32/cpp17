/*
   Handling Copying and Assignment
   Disallowing Assignment and Pass-By-Value
*/

#include <iostream>
#include "Spreadsheet.hpp"

void printSpreadsheet(Spreadsheet s)
{
    std::cout << "s Width : " << s.getWidth() << std::endl;
    std::cout << "s Height : " << s.getHeight() << std::endl;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    Spreadsheet s3(4, 3);
    printSpreadsheet(s3); // s1 has a pointer that no longer points to valid memory. This is called a dangling pointer.

    std::cout << "--------------------------------------------------" << std::endl;

    Spreadsheet s1(2, 2), s2(4, 3);

    std::cout << "s1 Width : " << s1.getWidth() << std::endl;
    std::cout << "s1 Height : " << s1.getHeight() << std::endl;

    /*
    not only do the mCells pointers in s1 and s2 point to the same memory, but you have also
    orphaned the memory to which mCells in s1 previously pointed. This is called a memory leak.
    */
    s1 = s2;

    /*
        Whenever you have dynamically allocated memory in a class,
        you should write your own copy constructor and assignment operator
        to provide a deep copy of the memory.
    */

    std::cout << "--------------------------------------------------" << std::endl;

    std::cout << "s1 Width after assignment : " << s1.getWidth() << std::endl;
    std::cout << "s1 Height after assignment : " << s1.getHeight() << std::endl;

    std::cout << "--------------------------------------------------" << std::endl;

    SpreadsheetCell sc1(5.66);
    SpreadsheetCell sc2(8.98);

    s1.setCellAt(2, 1, sc1);
    s1.setCellAt(3, 2, sc2);

    std::cout << "Cell value at (2,1): " << s1.getCellAt(2, 1).getValue() << std::endl;
    std::cout << "Cell value at (3,2): " << s1.getCellAt(3, 2).getValue() << std::endl;

    return 0;
}