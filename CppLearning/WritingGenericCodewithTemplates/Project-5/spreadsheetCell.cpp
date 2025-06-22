#include "spreadsheetCell.hpp"

SpreadsheetCell::SpreadsheetCell(float value) : mValue(value)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell &rh) : mValue(rh.mValue)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

SpreadsheetCell &SpreadsheetCell::operator=(const SpreadsheetCell &rh)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    if (this != &rh)
    {
        mValue = rh.mValue;
    }

    return *this;
}

SpreadsheetCell::SpreadsheetCell(SpreadsheetCell &&rh) : mValue(std::move(rh.mValue))
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

SpreadsheetCell &SpreadsheetCell::operator=(SpreadsheetCell &&rh)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    if (this != &rh)
    {
        mValue = std::move(rh.mValue);
    }

    return *this;
}

float SpreadsheetCell::getValue() const
{
    return mValue;
};

SpreadsheetCell::~SpreadsheetCell()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
