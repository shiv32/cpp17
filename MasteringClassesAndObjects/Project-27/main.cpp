/*
        OPERATOR OVERLOADING
             Third Attempt: Global operator+

                    Implicit conversions allow you to use an operator+ method to add
                    your SpreadsheetCell objects to ints and doubles. The operator is not
                    commutative.

             eg.  aThirdCell = myCell + 4; // Works fine.
                  aThirdCell = myCell + 5.6; // Works fine.
                  aThirdCell = 4 + myCell; // FAILS TO COMPILE!
                  aThirdCell = 5.6 + myCell; // FAILS TO COMPILE!

                    The implicit conversion works fine when the SpreadsheetCell object
                    is on the left of the operator, but it doesn’t work when it’s on the right.

                    The problem is that the operator+ method must be called on a
                    SpreadsheetCell object, and that object must be on the left-hand side of the
                    operator+. That’s just the way the C++ language is defined.

                    You can get it to work if you replace the in-class operator+
                    method with a global operator+ function that is not tied to any particular
                    object.

                        eg. SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
                                {
                                return SpreadsheetCell(lhs.getValue() + rhs.getValue());
                                }

                                Declare the operator in the header file

                        eg.
                                class SpreadsheetCell
                                {

                                };

                                SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);


                                Now all four of the addition lines work

                        eg. aThirdCell = myCell + 4; // Works fine.
                            aThirdCell = myCell + 5.6; // Works fine.
                            aThirdCell = 4 + myCell; // Works fine.
                            aThirdCell = 5.6 + myCell; // Works fine.


                            aThirdCell = 4.5 + 5.5;

                        It compiles and runs, but it’s not calling the operator+ you
                        wrote. It does normal double addition of 4.5 and 5.5.

                        aThirdCell = 10;

                        To make this assignment work, there should be a SpreadsheetCell object on the right-hand side.
                        The compiler will discover a non-explicit user-defined constructor that takes a double, will use
                        this constructor to implicitly convert the double value into a temporary SpreadsheetCell object,
                        and will then call the assignment operator.

                        In C++, you cannot change the precedence of operators.
                        eg.
                            * and / are always evaluated before + and -.

                        C++ also does not allow you to invent new operator symbols,
                        or to change the number of arguments for operators.
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