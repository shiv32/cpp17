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
  ~SpreadsheetCell();

  SpreadsheetCell(const SpreadsheetCell &src); // Copy Constructor
  // SpreadsheetCell(const SpreadsheetCell &src) = default; //
  // compiler-generated copy constructor
  //  SpreadsheetCell(const SpreadsheetCell &src) = delete;

  // Assignment Operator
  SpreadsheetCell &operator=(const SpreadsheetCell &rhs); // user defined
  // SpreadsheetCell& operator=(const SpreadsheetCell& rhs) = default;
  // //compiler-generated copy assignment operator SpreadsheetCell&
  // operator=(const SpreadsheetCell& rhs) = delete;

  void setValue(double mValue);
  double getValue() const;
  void setString(std::string_view inString);
  std::string getString() const;

  // Overloading Unary Minus and Unary Plus
  SpreadsheetCell operator-() const;
  SpreadsheetCell operator+() const;

  friend double operator+(const SpreadsheetCell &c, double d);
  friend double operator+(double d, const SpreadsheetCell &c);

  // Overloading Increment and Decrement
  SpreadsheetCell &operator++();   // Prefix
  SpreadsheetCell operator++(int); // Postfix
  SpreadsheetCell &operator--();   // Prefix
  SpreadsheetCell operator--(int); // Postfix

  // conversion operator to convert SpreadsheetCells to double.
  operator double() const;
  //explicit operator double() const; // Solving Ambiguity Problems with Explicit Conversion Operators

  // conversion operator to convert SpreadsheetCells to string.
  operator std::string() const;

private:
  std::string doubleToString(double inValue) const;
  double stringToDouble(std::string_view inString) const;
  double mValue{};
};

// OVERLOADING THE INSERTION AND EXTRACTION OPERATORS
// you must write the extraction and insertion operators as global functions.
std::ostream &operator<<(std::ostream &ostr, const SpreadsheetCell &cell); // insertion
std::istream &operator>>(std::istream &istr, SpreadsheetCell &cell);       // extraction