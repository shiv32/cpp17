/*
    Overloading Comparison Operators
        The comparison operators are >, <, and ==

        They should be global functions so that you can use implicit conversion
        on both the left-hand side and the right-hand side of the operator.

        The comparison operators all return a bool.

        You have to replace <op> with ==, <, >, !=, <=, and >=, resulting in six functions.

            class SpreadsheetCell
                {

                };

            bool operator<op>(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)

        Here is the definition of operator==

                bool operator==(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
                {
                    return (lhs.getValue() == rhs.getValue());
                }

        Once you’ve implemented == and <, you can write the rest of the comparison operators in terms of
        those two.

            eg. Definition of operator>= that uses operator<

                    bool operator>=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
                        {
                            return !(lhs < rhs);
                        }

        You can use these operators to compare SpreadsheetCells to other SpreadsheetCells, and also to
        doubles and ints.

            eg.
                 if (myCell > aThirdCell || myCell < 10)
                 {
                    cout << myCell.getValue() << endl;
                 }

        Note->  Most of the time, performing equality or inequality tests on floating point values 
                is not a good idea. You should use an epsilon test.

*/

#include "Spreadsheet.hpp"
#include <iostream>

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    SpreadsheetCell myCell(4), aThirdCell(2);

    if (myCell > aThirdCell || myCell < 10)
    {
        std::cout << myCell.getValue() << std::endl;
    }

    aThirdCell = 20;

    if (myCell > aThirdCell && myCell < 10)
    {
        std::cout << myCell.getValue() << std::endl;
    }
    else
    {
        std::cout << "Condition failed !" << std::endl;
    }

    return 0;
}