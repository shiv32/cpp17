/*
   Moving Object Data Members
*/

#include <iostream>
#include "Spreadsheet.hpp"

void printSpreadsheet(Spreadsheet s)
{
    std::cout << "s Width : " << s.getWidth() << std::endl;
    std::cout << "s Height : " << s.getHeight() << std::endl;
    std::cout << "s Sheetname : " << s.getSheetname() << std::endl;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    Spreadsheet s3(4, 3, "billsheet");
    printSpreadsheet(std::move(s3));

    std::cout << "--------------------------------------------------" << std::endl;

    Spreadsheet s1(2, 2, "vegitablebill"), s2(4, 3, "telephonebill");

    std::cout << "s1 Width : " << s1.getWidth() << std::endl;
    std::cout << "s1 Height : " << s1.getHeight() << std::endl;
    std::cout << "s1 Sheetname : " << s1.getSheetname() << std::endl;

    s1 = std::move(s2);

    std::cout << "--------------------------------------------------" << std::endl;

    std::cout << "s1 Width after assignment : " << s1.getWidth() << std::endl;
    std::cout << "s1 Height after assignment : " << s1.getHeight() << std::endl;
    std::cout << "s1 Sheetname : " << s1.getSheetname() << std::endl;

    std::cout << "--------------------------------------------------" << std::endl;

    SpreadsheetCell sc1(5.66);
    SpreadsheetCell sc2(8.98);

    s1.setCellAt(2, 1, sc1);
    s1.setCellAt(3, 2, sc2);

    std::cout << "Cell value at (2,1): " << s1.getCellAt(2, 1).getValue() << std::endl;
    std::cout << "Cell value at (3,2): " << s1.getCellAt(3, 2).getValue() << std::endl;

    return 0;
}