/*
        Overloading Arithmetic Operators
            Declarations of +, -, *, and /, where you have to replace <op> with +, -, *, and /, 
            resulting in four functions. 

            SpreadsheetCell operator<op>(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
           
            You can also overload %, but it doesn’t make sense for the double values stored in SpreadsheetCells.
          
            For operator/, the only tricky aspect is remembering to check for division by zero.
            This implementation throws an exception if division by zero is detected.

                eg.
                    SpreadsheetCell operator/(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
                        {
                            if (rhs.getValue() == 0) {
                            throw invalid_argument("Divide by zero.");
                        }
                            return SpreadsheetCell(lhs.getValue() / rhs.getValue());
                        }

    */

#include "Spreadsheet.hpp"
#include <iostream>

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    SpreadsheetCell myCell(4);

    SpreadsheetCell aThirdCell;

    aThirdCell = myCell + 4; // Works fine.
    std::cout << "Cell value at aThirdCell : " << aThirdCell.getValue() << std::endl;
    aThirdCell = myCell + 5.6; // Works fine.
    std::cout << "Cell value at aThirdCell : " << aThirdCell.getValue() << std::endl;

    // aThirdCell = 4 + myCell;   // FAILS TO COMPILE! with  in-class operator+ method
    // aThirdCell = 5.6 + myCell; // FAILS TO COMPILE! with  in-class operator+ method

    aThirdCell = 4 + myCell; // Works fine with global operator+ function that is not tied to any particular object.
    std::cout << "Cell value at aThirdCell : " << aThirdCell.getValue() << std::endl;
    aThirdCell = 5.6 + myCell; // Works fine with global operator+ function that is not tied to any particular object.
    std::cout << "Cell value at aThirdCell : " << aThirdCell.getValue() << std::endl;

    aThirdCell = 4.5 + 5.5;
    std::cout << "Cell value at aThirdCell : " << aThirdCell.getValue() << std::endl;

    return 0;
}