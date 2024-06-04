#pragma once

#include <string>
#include <string_view>

class SpreadsheetCell
{
public:
    SpreadsheetCell() = default;
    SpreadsheetCell(double initialValue);
    SpreadsheetCell(std::string_view initialValue);

    // Destructor
    ~SpreadsheetCell();

    // SpreadsheetCell(const SpreadsheetCell &src) = default;
    SpreadsheetCell(const SpreadsheetCell &src) = delete;

    void setValue(double mValue);
    double getValue() const;
    void setString(std::string_view inString);
    std::string getString() const;

private:
    std::string doubleToString(double inValue) const;
    double stringToDouble(std::string_view inString) const;
    double mValue;
};