#include "SomeClass.hpp"

SomeClass::SomeClass(double mVal) : mCell(mVal)
{
}

SpreadsheetCell SomeClass::getSpreadsheetCellinstance()
{
    return mCell;
}