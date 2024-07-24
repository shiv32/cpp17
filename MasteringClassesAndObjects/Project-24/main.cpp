/*
        OPERATOR OVERLOADING
                Perform operations on objects, such as adding them, comparing them, or streaming them to or from files.

                eg. spreadsheets are really only useful when you can perform
                    arithmetic actions on them, such as summing an entire row of cells.

                     SpreadsheetCell objects should be able to add themselves to other
                     SpreadsheetCell objects and produces a third cell with the result.
                     The meaning of addition for SpreadsheetCells is the addition of the values of the cells.

        First Attempt: The add Method
                Declare and define an add() method for your SpreadsheetCell class.

*/

#include <iostream>
#include "Spreadsheet.hpp"

int main()
{

        system("clear && printf '\e[3J'"); // clean the terminal before output in linux

        auto sheet1 = std::make_shared<Spreadsheet>(5, 6);

        auto sc1 = std::make_shared<SpreadsheetCell>(50);
        auto sc2 = std::make_shared<SpreadsheetCell>(20);
        auto sc3 = sc1->add(sc2);
        sc3->setColor(SpreadsheetCell::Color::Yellow);
        
        sheet1->setCellAt(1, 1, sc3);

        auto &cell1 = sheet1->getCellAt(1, 1);

        std::cout << "Cell1 value at (1,1): " << cell1->getValue() << std::endl;
        std::cout << "Cell2 value at (1,1) string : " << cell1->getString() << std::endl;
        std::cout << "Cell2 color at (1,1) : " << cell1->getColor() << std::endl;

        return 0;
}