#include "SpreadsheetCell.hpp"
#include <iostream>

using namespace std;

SpreadsheetCell::SpreadsheetCell(double initialValue)
{

    mValue = initialValue;

    std::cout << __PRETTY_FUNCTION__ << " mValue : " << mValue << std::endl;
}

// Delegating Constructor
SpreadsheetCell::SpreadsheetCell(string_view initialValue) : SpreadsheetCell(stringToDouble(initialValue))
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

SpreadsheetCell::~SpreadsheetCell()
{
    std::cout << __PRETTY_FUNCTION__ << " mValue : " << mValue << std::endl;
}

void SpreadsheetCell::setValue(double mValue)
{
    this->mValue = mValue;
}
double SpreadsheetCell::getValue() const
{
    return mValue;
}
void SpreadsheetCell::setString(string_view inString)
{
    mValue = stringToDouble(inString);
}
string SpreadsheetCell::getString() const
{
    return doubleToString(mValue);
}
string SpreadsheetCell::doubleToString(double inValue) const
{
    return to_string(inValue);
}
double SpreadsheetCell::stringToDouble(string_view inString) const
{
    return strtod(inString.data(), nullptr);
}