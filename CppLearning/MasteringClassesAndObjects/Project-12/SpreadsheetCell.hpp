#pragma once

#include <string>
#include <string_view>

class SpreadsheetCell
{
public:
  SpreadsheetCell();
  SpreadsheetCell(double initialValue);
  SpreadsheetCell(std::string_view initialValue);

  // Destructor
  //~SpreadsheetCell() = default;

  // SpreadsheetCell(const SpreadsheetCell &src); // Copy Constructor
  // SpreadsheetCell(const SpreadsheetCell &src) = default; //
  // compiler-generated copy constructor
  //  SpreadsheetCell(const SpreadsheetCell &src) = delete;

  // Assignment Operator
  // SpreadsheetCell &operator=(const SpreadsheetCell &rhs); // user defined
  // SpreadsheetCell& operator=(const SpreadsheetCell& rhs) = default;
  // //compiler-generated copy assignment operator SpreadsheetCell&
  // operator=(const SpreadsheetCell& rhs) = delete;

  void setValue(double mValue);
  double getValue() const;
  void setString(std::string_view inString);
  std::string getString() const;
  size_t getTotalNumOfAccess() const;

  static std::string doubleToString(double inValue);
  static double stringToDouble(std::string_view inString);

private:
  double mValue{};
  mutable size_t mNumAccesses = 0;
};