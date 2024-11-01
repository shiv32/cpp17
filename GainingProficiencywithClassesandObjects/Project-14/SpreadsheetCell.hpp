#pragma once

#include <string>
#include <string_view>

class SpreadsheetCell
{
public:
    // SpreadsheetCell(double initialValue); // No default constructor

    void setValue(double mValue);
    double getValue() const;

    void setString(std::string_view inString);
    std::string getString() const;

private:
    std::string doubleToString(double inValue) const;
    double stringToDouble(std::string_view inString) const;
    double mValue;
};