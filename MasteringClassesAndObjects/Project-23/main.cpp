/*
        ENUMERATED TYPES INSIDE CLASSES
                If you want to define a number of constants inside a class, you should use an enumerated type
                instead of a collection of #defines.

                eg. You can add support for cell coloring to the SpreadsheetCell class.

*/

#include <iostream>
#include "Spreadsheet.hpp"

int main()
{

        system("clear && printf '\e[3J'"); // clean the terminal before output in linux

        auto sheet1 = std::make_shared<Spreadsheet>(5, 6);

        auto sc1 = std::make_shared<SpreadsheetCell>(50);
        sc1->setColor(SpreadsheetCell::Color::Yellow);
        sheet1->setCellAt(1, 1, sc1);

        auto &cell1 = sheet1->getCellAt(1, 1);

        std::cout << "Cell1 value at (1,1): " << cell1->getValue() << std::endl;
        std::cout << "Cell2 value at (1,1) string : " << cell1->getString() << std::endl;
        std::cout << "Cell2 color at (1,1) : "<<cell1->getColor() << std::endl;

        return 0;
}