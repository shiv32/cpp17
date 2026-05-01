#include "DoubleSpreadsheetCell.hpp"

void DoubleSpreadsheetCell::set(double inDouble)
{
    mValue = inDouble;
}

void DoubleSpreadsheetCell::set(std::string_view inString)
{
    mValue = stringToDouble(inString);
}

std::string DoubleSpreadsheetCell::getString() const
{
    return (mValue.has_value() ? doubleToString(mValue.value()) : "");
}

std::string DoubleSpreadsheetCell::doubleToString(double inValue)
{
    return std::to_string(inValue);
}

double DoubleSpreadsheetCell::stringToDouble(std::string_view inValue)
{
    return strtod(inValue.data(), nullptr);
}
