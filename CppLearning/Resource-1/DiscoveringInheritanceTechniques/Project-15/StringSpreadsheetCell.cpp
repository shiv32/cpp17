#include "StringSpreadsheetCell.hpp"

StringSpreadsheetCell::StringSpreadsheetCell(const DoubleSpreadsheetCell &inDoubleCell)
{
    mValue = inDoubleCell.getString();
}

void StringSpreadsheetCell::set(std::string_view inString)
{
    mValue = inString;
}

std::string StringSpreadsheetCell::getString() const
{
    return mValue.value_or("");
}

StringSpreadsheetCell operator+(const StringSpreadsheetCell &lhs,
                                const StringSpreadsheetCell &rhs)
{
    StringSpreadsheetCell newCell;
    newCell.set(lhs.getString() + rhs.getString());
    return newCell;
}
