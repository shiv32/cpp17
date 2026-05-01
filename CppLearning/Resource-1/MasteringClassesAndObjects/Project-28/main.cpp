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
                            if (rhs.getValue() == 0)
                            {
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

    SpreadsheetCell myCell(4), aThirdCell;

    aThirdCell = myCell / 4;
    std::cout << "Cell value at aThirdCell : " << aThirdCell.getValue() << std::endl;

    aThirdCell = 4 / myCell;
    std::cout << "Cell value at aThirdCell : " << aThirdCell.getValue() << std::endl;

    try
    {
        aThirdCell = myCell / 0;
        std::cout << "Cell value at aThirdCell : " << aThirdCell.getValue() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "exception : " << e.what() << '\n';
    }

    return 0;
}