/*
   Reference Data Members
        Reference data members must be initialized when an object is created 
        because references cannot be reseated or left uninitialized. 
        This initialization is typically done through the constructor initializer list.

   eg.  The Spreadsheet class must know about the SpreadsheetApplication class,
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

        std::cout << "GetDefaultAppSheetName : " << sheet1->GetDefaultAppSheetName() << std::endl;

        return 0;
}