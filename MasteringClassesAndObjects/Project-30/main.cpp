/*
    Overloading Comparison Operators
        The comparison operators are >, <, and ==

        They should be global functions so that you can use implicit conversion
        on both the left-hand side and the right-hand side of the operator.
        
        The comparison operators all return a bool.

        You have to replace <op> with ==, <, >, !=, <=, and >=, resulting in six functions.

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
               
*/

#include "Spreadsheet.hpp"
#include <iostream>

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    SpreadsheetCell myCell(4), aThirdCell(2);

    aThirdCell += 5.4;

    std::cout << "Cell value at aThirdCell : " << aThirdCell.getValue() << std::endl;

    aThirdCell = myCell + 4;
    
    std::cout << "Cell value at aThirdCell : " << aThirdCell.getValue() << std::endl;

    return 0;
}