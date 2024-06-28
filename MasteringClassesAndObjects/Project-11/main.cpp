/*
    static Methods

    In Class SpreadsheetCell
    It has two helper methods: stringToDouble() and doubleToString().
    These methods don’t access information about specific objects, so they could be static. 
*/

#include <iostream>
#include "Spreadsheet.hpp"
#include <vector>

std::unique_ptr<Spreadsheet> createObject()
{
    // return Spreadsheet(3, 2);
    return std::make_unique<Spreadsheet>(3, 2);
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Spreadsheet s(2, 3);
    auto s = std::make_unique<Spreadsheet>(2, 3);

    std::cout << "s Width : " << s->getWidth() << std::endl;
    std::cout << "s Height : " << s->getHeight() << std::endl;
    std::cout << "s Sheetname : " << s->getSheetname() << std::endl;

    s = createObject();

    std::cout << "s Width after assignment : " << s->getWidth() << std::endl;
    std::cout << "s Height after assignment : " << s->getHeight() << std::endl;
    std::cout << "s Sheetname after assignment : " << s->getSheetname() << std::endl;

    // Spreadsheet s2(std::move(s));
    std::unique_ptr<Spreadsheet> s2(std::move(s));

    std::cout << "s2 Width after assignment : " << s2->getWidth() << std::endl;
    std::cout << "s2 Height after assignment : " << s2->getHeight() << std::endl;
    std::cout << "s2 Sheetname after assignment : " << s2->getSheetname() << std::endl;

    // Spreadsheet s3(5, 6);
    auto s3 = std::make_unique<Spreadsheet>(5, 6);

    std::cout << "s3 Width : " << s3->getWidth() << std::endl;
    std::cout << "s3 Height : " << s3->getHeight() << std::endl;
    std::cout << "s3 Sheetname : " << s3->getSheetname() << std::endl;

    // s3 = std::move(s2);
    s3 = std::move(s2);

    std::cout << "s3 Width after assignment : " << s3->getWidth() << std::endl;
    std::cout << "s3 Height after assignment : " << s3->getHeight() << std::endl;
    std::cout << "s3 Sheetname after assignment : " << s3->getSheetname() << std::endl;

    // Spreadsheet s1(4, 3);
    auto s1 = std::make_shared<Spreadsheet>(4, 3);

    // SpreadsheetCell sc1(5.66);
    auto sc1 = std::make_shared<SpreadsheetCell>(SpreadsheetCell::doubleToString(5.66));

    // SpreadsheetCell sc2(8.98);
    auto sc2 = std::make_shared<SpreadsheetCell>(SpreadsheetCell::stringToDouble("8.98"));
    

    s1->setCellAt(2, 1, sc1);
    s1->setCellAt(2, 0, sc2);

    std::cout << "Cell value at (2,1): " << s1->getCellAt(2, 1)->getValue() << std::endl;
    std::cout << "Cell value at (2,0): " << s1->getCellAt(2, 0)->getValue() << std::endl;

    return 0;
}