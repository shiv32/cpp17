/*
        OPERATOR OVERLOADING
             Second Attempt: Overloaded operator+ as a Method

             Implicit Conversions
                You can also add a cell to a string_view, a double, or an int.

                You can prevent the implicit construction of a SpreadsheetCell
                from a string_view by marking that constructor with the explicit keyword.

                eg . explicit SpreadsheetCell(std::string_view initialValue);

                The explicit keyword goes only in the class definition.
                explicit keyword applied to constructors that can be called with
                one argument or multiparameter constructors with default values for
                parameters.

                The selection of an implicit constructor might be inefficient,
                because temporary objects must be created. To avoid implicit construction for
                adding a double, you could write a second operator+.

                eg. SpreadsheetCell SpreadsheetCell::operator+(double rhs) const
                      {
                      return SpreadsheetCell(getValue() + rhs);
                      }


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