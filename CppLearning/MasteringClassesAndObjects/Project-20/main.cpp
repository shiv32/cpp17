/*
        const Reference Data Members
                Your reference members can refer to const objects just as normal references can refer to const
                objects.

        eg.  You might decide that Spreadsheets should only have a const reference to
             the application object.

        Spreadsheet(size_t width, size_t height,const SpreadsheetApplication& theApp);
        const SpreadsheetApplication& mTheApp;

        Important difference between using a const reference versus a non-const reference. 
                The const reference SpreadsheetApplication data member can only be used to call const methods on
                the SpreadsheetApplication object. 
                If you try to call a non-const method through a const reference, you will get a compilation error.
        
        Possible to have a static reference member or a static const reference member.

*/

#include <iostream>
#include "Spreadsheet.hpp"

int main()
{

        system("clear && printf '\e[3J'"); // clean the terminal before output in linux

        auto sheet1 = std::make_unique<Spreadsheet>();

        std::cout << "GetDefaultAppSheetName call const fun : " << sheet1->GetDefaultAppSheetName() << std::endl;

        return 0;
}