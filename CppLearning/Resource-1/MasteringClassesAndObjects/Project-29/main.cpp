/*
        Overloading the Arithmetic Shorthand Operators
            These operators differ from the basic arithmetic operators in that they change the object
            on the left-hand side of the operator instead of creating a new object.

            Like the assignment operator, they generate a result that is a reference to the modified object.

            The arithmetic shorthand operators always require an object on the left-hand side,
            so you should write them as methods, not as global functions.

            eg.
                SpreadsheetCell& operator+=(const SpreadsheetCell& rhs);
                SpreadsheetCell& operator-=(const SpreadsheetCell& rhs);
                SpreadsheetCell& operator*=(const SpreadsheetCell& rhs);
                SpreadsheetCell& operator/=(const SpreadsheetCell& rhs);

                The implementation for operator+=

                SpreadsheetCell& SpreadsheetCell::operator+=(const SpreadsheetCell& rhs)
                    {
                        set(getValue() + rhs.getValue());
                        return *this;
                    }


                When you have both a normal and a shorthand version of a certain operator, it’s recommended to
                implement the normal one in terms of the shorthand version to avoid code duplication.

                eg.
                   SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
                        {
                            auto result(lhs); // Local copy
                            result += rhs;   // Forward to op=() version
                            return result;
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