/*
        OPERATOR OVERLOADING
             Second Attempt: Overloaded operator+ as a Method
                 Add two cells with the plus sign the way that you add two ints
                 or two doubles.

                 eg.    SpreadsheetCell myCell(4), anotherCell(5);
                        SpreadsheetCell aThirdCell = myCell + anotherCell;


*/

#include <iostream>
#include "Spreadsheet.hpp"

int main()
{

        system("clear && printf '\e[3J'"); // clean the terminal before output in linux

        auto sheet1 = std::make_shared<Spreadsheet>(5, 6);

        auto sc1 = std::make_shared<SpreadsheetCell>(50);
        auto sc2 = std::make_shared<SpreadsheetCell>(20);

        auto sc3 = sc1+sc2; //global operator+ needed

        //auto sc3 = sc1->operator+(sc2);  ////class member operator+ needed

        sc3->setColor(SpreadsheetCell::Color::Yellow);
        
        sheet1->setCellAt(1, 1, sc3);

        auto &cell1 = sheet1->getCellAt(1, 1);

        std::cout << "Cell1 value at (1,1): " << cell1->getValue() << std::endl;
        std::cout << "Cell2 value at (1,1) string : " << cell1->getString() << std::endl;
        std::cout << "Cell2 color at (1,1) : " << cell1->getColor() << std::endl;

        return 0;
}