/*
    const Methods
        A const object is an object whose value cannot be changed.

        eg. The SpreadsheetCell class with the methods that don’t change any data members marked
            as const.

            double getValue() const;
            std::string getString() const;

            You can call const and non-const methods on a non-const object.
            You can only call const methods on a const object.

    mutable Data Members
        Sometimes you write a method that is “logically” const but happens to change a data member
        of the object.
*/

#include <iostream>
#include "Spreadsheet.hpp"

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    SpreadsheetCell myCell(5);

    std::cout << myCell.getValue() << std::endl; // OK

    myCell.setString("6"); // OK

    const SpreadsheetCell &myCellConstRef = myCell;

    std::cout << myCellConstRef.getValue() << std::endl;  // OK
    std::cout << myCellConstRef.getString() << std::endl; // OK

    // myCellConstRef.setString("6");                      // Compilation Error!

    std::cout << "getTotalNumOfAccess : " << myCellConstRef.getTotalNumOfAccess() << std::endl; // OK

    return 0;
}