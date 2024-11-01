#include "SpreadsheetCell.hpp"
#include <iostream>

using namespace std;

// stand-alone function (not method)
void printCell(const SpreadsheetCell &cell)
{
    cout << cell.getString() << endl;
}

void SpreadsheetCell::setValue(double mValue)
{
    // this pointer usage
    this->mValue = mValue;
    printCell(*this);
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
