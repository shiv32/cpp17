/*
        OPERATOR OVERLOADING
             Third Attempt: Global operator+

             Implicit conversions allow you to use an operator+ method to add your SpreadsheetCell objects
             to ints and doubles.
             The operator is not commutative.

             eg.  aThirdCell = myCell + 4; // Works fine.
                  aThirdCell = myCell + 5.6; // Works fine.
                  aThirdCell = 4 + myCell; // FAILS TO COMPILE!
                  aThirdCell = 5.6 + myCell; // FAILS TO COMPILE!

              The implicit conversion works fine when the SpreadsheetCell object is on the left of the operator,
              but it doesn’t work when it’s on the right. 
              
              The problem is that the operator+ method must be called on a SpreadsheetCell
              object, and that object must be on the left-hand side of the operator+. 
              That’s just the way the C++ language is defined.

              You can get it to work if you replace the in-class operator+ method with a global operator+ function
              that is not tied to any particular object. 

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

             eg.  aThirdCell = myCell + 4; // Works fine.
                  aThirdCell = myCell + 5.6; // Works fine.
                  aThirdCell = 4 + myCell; // Works fine.
                  aThirdCell = 5.6 + myCell; // Works fine.


                  aThirdCell = 4.5 + 5.5;

                  It compiles and runs, but it’s not calling the operator+ you wrote. It does normal double addition
                  of 4.5 and 5.5.

                  aThirdCell = 10;
                  
                  To make this assignment work, there should be a SpreadsheetCell object on the right-hand side.
                  The compiler will discover a non-explicit user-defined constructor that takes a double, will use this
                  constructor to implicitly convert the double value into a temporary SpreadsheetCell object, and
                  will then call the assignment operator.
*/

#include "Spreadsheet.hpp"
#include <iostream>

int main() {

  system(
      "clear && printf '\e[3J'"); // clean the terminal before output in linux

  auto sheet1 = std::make_shared<Spreadsheet>(5, 6);

  auto sc1 = std::make_shared<SpreadsheetCell>(50);
  auto sc2 = std::make_shared<SpreadsheetCell>(20);

  // auto sc3 = sc1+sc2; //global operator+ needed for smart pointer

  // auto sc3 = sc1->operator+(sc2);  //class member operator+ needed

  // sc3->setColor(SpreadsheetCell::Color::Yellow);

  // sheet1->setCellAt(1, 1, sc3);

  // auto &cell1 = sheet1->getCellAt(1, 1);

  // std::cout << "Cell1 value at (1,1): " << cell1->getValue() << std::endl;
  // std::cout << "Cell2 value at (1,1) string : " << cell1->getString() <<
  // std::endl; std::cout << "Cell2 color at (1,1) : " << cell1->getColor() <<
  // std::endl;

  //---------------------------------------------------------
  SpreadsheetCell myCell(4), anotherCell(5);

  SpreadsheetCell aThirdCell = myCell + anotherCell;

  // or

  // auto aThirdCell = myCell.operator+(anotherCell);

  std::cout << "Cell value at aThirdCell : " << aThirdCell.getValue()
            << std::endl;

  //---------------------------(Implicit Conversions)--------------------------

  SpreadsheetCell myCell2(4), aThirdCell2;

  std::string str = "6";

  /*
 when the compiler sees the line trying to add a SpreadsheetCell to a
 string_view, it calls the string_view SpreadsheetCell constructor to create a
 temporary SpreadsheetCell to pass to operator+.
 */
  aThirdCell2 = myCell2 + std::string_view(str);
  // or
  // aThirdCell2 = myCell2.operator+(std::string_view(str));

  std::cout << "Cell value at aThirdCell2 : " << aThirdCell2.getValue()
            << std::endl;

  /*
  when the compiler sees a SpreadsheetCell trying to add itself to double, it
  finds the SpreadsheetCell constructor that takes a double and constructs a
  temporary SpreadsheetCell object to pass to operator+.
  */
  aThirdCell2 = myCell2 + 5.6;

  std::cout << "Cell value at aThirdCell2 : " << aThirdCell2.getValue()
            << std::endl;

  aThirdCell2 = myCell2 + 4;

  std::cout << "Cell value at aThirdCell2 : " << aThirdCell2.getValue()
            << std::endl;

  return 0;
}