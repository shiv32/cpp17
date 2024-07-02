/*
    Method Overloading
        Overload the function or method name by using it for multiple functions,
        as long as the number and/or types of the parameters differ

        eg. In the SpreadsheetCell class you can rename both setString() and
            setValue() to set().

    Overloading Based on const
         The compiler calls the const method if you have a const object,
         and the non-const method if you have a non-const object.

         The implementation of the const version and the non-const version is identical.
         To prevent code duplication, use the Scott Meyer’s const_cast() pattern.

         eg. The Spreadsheet class has a method called getCellAt() returning a non-const reference
             to a SpreadsheetCell.
             You can add a const overload that returns a const reference to a SpreadsheetCell


*/

#include <iostream>
#include "Spreadsheet.hpp"

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

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

    //-------------------------------------------------------------

    //Spreadsheet sheet1(5, 6);
     auto sheet1 = std::make_shared<Spreadsheet>(5,6);
      //auto s1 = std::make_shared<Spreadsheet>(4, 3);

     std::shared_ptr<Spreadsheet> &cell1 = sheet1;

    //const Spreadsheet sheet2(5, 6);
    //const SpreadsheetCell &cell2 = sheet2.getCellAt(1, 1);

    return 0;
}