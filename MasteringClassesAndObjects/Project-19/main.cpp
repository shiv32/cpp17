/*
   Reference Data Members

   eg.  The Spreadsheet class must then know about the SpreadsheetApplication class,
        and the SpreadsheetApplication class must know about the Spreadsheet class.
        This is a circular reference and cannot be solved with normal #includes.
        The solution is to use a forward declaration in one of the header files.


*/

#include <iostream>
#include "Spreadsheet.hpp"

int main()
{

        system("clear && printf '\e[3J'"); // clean the terminal before output in linux

        auto sheet1 = std::make_unique<Spreadsheet>();

        std::cout << "getAppSheetname : " << sheet1->getAppSheetname() << std::endl;

        return 0;
}