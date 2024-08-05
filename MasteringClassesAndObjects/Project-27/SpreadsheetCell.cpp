#include "SpreadsheetCell.hpp"
#include <iostream>

using namespace std;

SpreadsheetCell::SpreadsheetCell() {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
}

SpreadsheetCell::SpreadsheetCell(double initialValue) {

  mValue = initialValue;

  // std::cout << __PRETTY_FUNCTION__ << " mValue : " << mValue << std::endl;
}

// // Delegating Constructor
SpreadsheetCell::SpreadsheetCell(string_view initialValue)
    : SpreadsheetCell(stringToDouble(initialValue)) {
  // std::cout << __PRETTY_FUNCTION__ << std::endl;
}

//--------------------------- Copy constructor----------------------------------------

/*
    mValue is initialized using the copy constructor
*/
SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell &src)
    : mValue(src.mValue)
{
  // std::cout << __PRETTY_FUNCTION__ << std::endl;
}

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

SpreadsheetCell &SpreadsheetCell::operator=(const SpreadsheetCell &rhs)
{
  if (this == &rhs)
  {
    std::cout << "Self assignment : " << __PRETTY_FUNCTION__ << std::endl;

    return *this;
  }

  mValue = rhs.mValue;

  // std::cout << __PRETTY_FUNCTION__ << std::endl;

  return *this;
}

SpreadsheetCell::~SpreadsheetCell()
{
   std::cout << __PRETTY_FUNCTION__ << " mValue : " << mValue << std::endl;
}

void SpreadsheetCell::set(double mValue) {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  this->mValue = mValue;
}

// double SpreadsheetCell::getValue() const
// {
//   mNumAccesses++;
//   return mValue;
// }

void SpreadsheetCell::set(string_view inString) {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  mValue = stringToDouble(inString);
}

// std::string SpreadsheetCell::getString() const
// {
//   mNumAccesses++;
//   return doubleToString(mValue);
// }

size_t SpreadsheetCell::getTotalNumOfAccess() const { return mNumAccesses; }

string SpreadsheetCell::doubleToString(double inValue) {
  return to_string(inValue);
}
double SpreadsheetCell::stringToDouble(string_view inString) {
  return strtod(inString.data(), nullptr);
}

void SpreadsheetCell::setColor(Color color) { mColor = color; }

std::string SpreadsheetCell::getColor() const {
  switch (mColor) {
  case SpreadsheetCell::Color::Red:
    return "Red";

  case SpreadsheetCell::Color::Green:
    return "Green";

  case SpreadsheetCell::Color::Blue:
    return "Blue";
  case SpreadsheetCell::Color::Yellow:
    return "Yellow";

  default:
    return "Unknown";
  }

  return "Unknown";
}

// std::shared_ptr<SpreadsheetCell> SpreadsheetCell::add(const
// std::shared_ptr<SpreadsheetCell> &cell) const
// {
//   return std::make_shared<SpreadsheetCell>(getValue() + cell->getValue());
// }

// std::shared_ptr<SpreadsheetCell> SpreadsheetCell::operator+(const
// std::shared_ptr<SpreadsheetCell>& cell) const
// {
//   return std::make_shared<SpreadsheetCell>(getValue() + cell->getValue());
// }

// std::shared_ptr<SpreadsheetCell> operator+(const
// std::shared_ptr<SpreadsheetCell>& lhs,
//                                           const
//                                           std::shared_ptr<SpreadsheetCell>&
//                                           rhs)
// {
//   return std::make_shared<SpreadsheetCell>(lhs->getValue() +
//   rhs->getValue());
// }

SpreadsheetCell SpreadsheetCell::operator+(const SpreadsheetCell &cell) const {
  std::cout << __PRETTY_FUNCTION__ << std::endl;

  return SpreadsheetCell(getValue() + cell.getValue());
}

SpreadsheetCell SpreadsheetCell::operator+(double rhs) const {
  std::cout << __PRETTY_FUNCTION__ << std::endl;

  return SpreadsheetCell(getValue() + rhs);
}

SpreadsheetCell operator+(const SpreadsheetCell &lhs,
                          const SpreadsheetCell &rhs) 
{
  return SpreadsheetCell(lhs.getValue() + rhs.getValue());
}