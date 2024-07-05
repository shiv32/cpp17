/*
    Inline Methods
        The compiler should insert the method’s body directly into the code where the method is called. 
        This process is called inlining, and methods that want this behavior are called inline methods. 
        Inlining is safer than using #define macros.

        Specify an inline method by placing the inline keyword in front of its name in
        the method definition. 


        eg. Make the accessor methods of the SpreadsheetCell class inline.

                inline double SpreadsheetCell::getValue() const
                {
                }

                inline std::string SpreadsheetCell::getString() const
                {
                }

        C++ provides an alternate syntax for declaring inline methods that doesn’t use the inline keyword at all. 
        You place the method definition directly in the class definition.

        eg.

            class SpreadsheetCell
            {
            public:
                double SpreadsheetCell::getValue() const  { }
                std::string SpreadsheetCell::getString() const{}
            }
*/

#include <iostream>
#include "Spreadsheet.hpp"

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    //----------------------------- Method Overloading demo ----------------------------------
    SpreadsheetCell myCell(5);

    std::cout << myCell.getValue() << std::endl; // OK

    myCell.set(8);
    // OK
    std::cout << myCell.getValue() << std::endl; // OK

    myCell.set("6"); // OK

    const SpreadsheetCell &myCellConstRef = myCell;

    std::cout << myCellConstRef.getValue() << std::endl;  // OK
    std::cout << myCellConstRef.getString() << std::endl; // OK

    // myCellConstRef.set("6");                      // Compilation Error!

    std::cout << "getTotalNumOfAccess : " << myCellConstRef.getTotalNumOfAccess() << std::endl; // OK

    //------------------------ Overloading Based on const demo -------------------------------------

    // Spreadsheet sheet1(5, 6);
    auto sheet1 = std::make_shared<Spreadsheet>(5, 6);

    auto sc1 = std::make_shared<SpreadsheetCell>(5.66);
    sheet1->setCellAt(1, 1, sc1);

    // SpreadsheetCell& cell1 = sheet1.getCellAt(1, 1);
    auto &cell1 = sheet1->getCellAt(1, 1);

    std::cout << "Cell1 value at (1,1): " << cell1->getValue() << std::endl;

    // const Spreadsheet sheet2(5, 6);
    auto sheet2 = std::make_shared<const Spreadsheet>(5, 6);

    // const SpreadsheetCell& cell2 = sheet2.getCellAt(1, 1);
    const auto &cell2 = sheet2->getCellAt(1, 1);

    std::cout << "Cell2 value at (1,1): " << cell2->getValue() << std::endl;

    return 0;
}