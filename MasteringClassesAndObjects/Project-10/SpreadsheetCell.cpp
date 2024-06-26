#include "SpreadsheetCell.hpp"
#include <iostream>

using namespace std;

SpreadsheetCell::SpreadsheetCell()
{
  // std::cout << __PRETTY_FUNCTION__ << std::endl;
}

SpreadsheetCell::SpreadsheetCell(double initialValue)
{

  mValue = initialValue;

  // std::cout << __PRETTY_FUNCTION__ << " mValue : " << mValue << std::endl;
}

// Delegating Constructor
SpreadsheetCell::SpreadsheetCell(string_view initialValue)
    : SpreadsheetCell(stringToDouble(initialValue))
{
  // std::cout << __PRETTY_FUNCTION__ << std::endl;
}

//--------------------------- Copy constructor ----------------------------------------

/*
    mValue is initialized using the copy constructor
*/
// SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell &src)
//     : mValue(src.mValue)
// {
//   // std::cout << __PRETTY_FUNCTION__ << std::endl;
// }

/*
    when you assign values to data members in the body of the copy constructor,
   you are using the assignment operator on them, not the copy constructor,
   because they have already been initialized.
*/
// SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell &src)
// {
//     std::cout << __PRETTY_FUNCTION__ << std::endl;

//     mValue = src.mValue;
// }
//----------------------------------------------------------------------------------

// SpreadsheetCell &SpreadsheetCell::operator=(const SpreadsheetCell &rhs)
// {
//   if (this == &rhs)
//   {
//     std::cout << "Self assignment : " << __PRETTY_FUNCTION__ << std::endl;

//     return *this;
//   }

//   mValue = rhs.mValue;

//   // std::cout << __PRETTY_FUNCTION__ << std::endl;

//   return *this;
// }

// SpreadsheetCell::~SpreadsheetCell()
// {
//   // std::cout << __PRETTY_FUNCTION__ << " mValue : " << mValue << std::endl;
// }

void SpreadsheetCell::setValue(double mValue) { this->mValue = mValue; }
double SpreadsheetCell::getValue() const { return mValue; }
void SpreadsheetCell::setString(string_view inString)
{
  mValue = stringToDouble(inString);
}
string SpreadsheetCell::getString() const { return doubleToString(mValue); }
string SpreadsheetCell::doubleToString(double inValue) const
{
  return to_string(inValue);
}
double SpreadsheetCell::stringToDouble(string_view inString) const
{
  return strtod(inString.data(), nullptr);
}