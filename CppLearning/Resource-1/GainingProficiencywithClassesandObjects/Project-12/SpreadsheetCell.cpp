#include "SpreadsheetCell.hpp"
#include <iostream>

using namespace std;

SpreadsheetCell::SpreadsheetCell(double initialValue)
{
    setValue(initialValue);
}

SpreadsheetCell::SpreadsheetCell(string_view initialValue)
{
    setString(initialValue);

    // The code will compile, link, and run, but will not do what you expect.
    // SpreadsheetCell(stringToDouble(initialValue));
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
