#pragma once

#include "SpreadsheetCell.hpp"

class SomeClass
{
public:
    SomeClass(double mVal);
    SpreadsheetCell getSpreadsheetCellinstance();

private:
    SpreadsheetCell mCell;
};