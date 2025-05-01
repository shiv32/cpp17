#pragma once

#include <iostream>

class SpreadsheetCell
{
private:
    float mValue{};

public:
    SpreadsheetCell(float value);
    ~SpreadsheetCell();

    // Overloading the equality operator (==) to compare the contents of SpreadsheetCell objects
    bool operator==(const SpreadsheetCell &other) const;
};
