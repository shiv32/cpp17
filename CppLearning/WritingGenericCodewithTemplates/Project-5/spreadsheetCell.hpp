#pragma once

#include <iostream>

class SpreadsheetCell
{
private:
    float mValue{};

public:
    SpreadsheetCell(float value);

    SpreadsheetCell(const SpreadsheetCell&);
    SpreadsheetCell& operator= (const SpreadsheetCell&);

    SpreadsheetCell(SpreadsheetCell &&rh);
    SpreadsheetCell& operator= (SpreadsheetCell &&rh);

    float getValue () const;

    ~SpreadsheetCell();
};
