/*
        NESTED CLASSES Part-1
                You can write nested classes and structs, declare type aliases, or create enumerated types.
                Anything declared inside a class is in the scope of that class.
                If it is public, you can access it outside the class by scoping
                it with the ClassName:: scope resolution syntax.

                eg. You might decide that the SpreadsheetCell class is really part of the Spreadsheet class.
                    And since it becomes part of the Spreadsheet class, you might as well rename it to Cell.


*/

#include <iostream>
#include "Spreadsheet.hpp"

int main()
{
        system("clear && printf '\e[3J'"); // clean the terminal before output in linux

        auto sheet1 = std::make_shared<Spreadsheet>(5, 6);
        auto sc1 = std::make_shared<Spreadsheet::Cell>(5.66);

        sheet1->setCellAt(1, 1, sc1);

        std::cout << "sheet1->getCellAt(1, 1) : " << sheet1->getCellAt(1, 1) << std::endl;

         auto &cell1 = sheet1->getCellAt(1, 1);

        std::cout << "Cell1 value at (1,1): " << cell1->getValue() << std::endl;
        std::cout << "Cell2 value at (1,1) string : " << cell1->getString() << std::endl;

        return 0;
}