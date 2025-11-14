#include "spreadsheetCell.hpp"

SpreadsheetCell::SpreadsheetCell(float value): mValue(value)
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl;
};

SpreadsheetCell::~SpreadsheetCell()
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl;
}

bool SpreadsheetCell::operator==(const SpreadsheetCell &other) const
{
    return this->mValue == other.mValue;
}
