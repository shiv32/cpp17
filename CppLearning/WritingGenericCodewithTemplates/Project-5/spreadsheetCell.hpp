#pragma once

#include <iostream>

class SpreadsheetCell
{
private:
    float mValue{};

public:
    SpreadsheetCell(float value);
    ~SpreadsheetCell();
};
