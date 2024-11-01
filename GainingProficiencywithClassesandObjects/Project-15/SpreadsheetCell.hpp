#pragma once

#include <string>
#include <string_view>

class SpreadsheetCell
{
public:
    SpreadsheetCell() = default;

    //class with only static methods for which you do not want to write any constructors
    //and you also do not want the compiler to generate the default constructor.
    //SpreadsheetCell() = delete;
    
    SpreadsheetCell(double initialValue);
    SpreadsheetCell(std::string_view initialValue);
   
    void setValue(double mValue);
    double getValue() const;
    void setString(std::string_view inString);
    std::string getString() const;

private:
    std::string doubleToString(double inValue) const;
    double stringToDouble(std::string_view inString) const;
    double mValue;
};