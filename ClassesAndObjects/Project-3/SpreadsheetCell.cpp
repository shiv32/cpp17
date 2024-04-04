#include "SpreadsheetCell.hpp"

void SpreadsheetCell::setValue(double inValue)
{
    mValue = inValue;
}
double SpreadsheetCell::getValue() const
{
    return mValue;
}