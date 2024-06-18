#include "Spreadsheet.hpp"

Spreadsheet::Spreadsheet(size_t width, size_t height)
    : mWidth(width), mHeight(height)
{
    mCells = new SpreadsheetCell*[mWidth];

    for (size_t i = 0; i < mWidth; i++)
    {
        mCells[i] = new SpreadsheetCell[mHeight];
    }
}

Spreadsheet::~Spreadsheet()
{
    for (size_t i = 0; i < mWidth; i++)
    {
        delete[] mCells[i];
    }
    delete[] mCells;
    mCells = nullptr;
}

void Spreadsheet::setCellAt(size_t x, size_t y, const SpreadsheetCell &cell)
{
    /*
    if (!inRange(x, mWidth) || !inRange(y, mHeight))
    {
        throw std::out_of_range("");
    }
    */

    verifyCoordinate(x, y);
    mCells[x][y] = cell;
}

SpreadsheetCell &Spreadsheet::getCellAt(size_t x, size_t y)
{
    /*
    if (!inRange(x, mWidth) || !inRange(y, mHeight))
    {
        throw std::out_of_range("");
    }
    */

    verifyCoordinate(x, y);
    return mCells[x][y];
}

void Spreadsheet::verifyCoordinate(size_t x, size_t y) const
{
    if (x >= mWidth || y >= mHeight)
    {
        throw std::out_of_range("");
    }
}

bool Spreadsheet::inRange(size_t value, size_t upper) const
{
    if (value >= upper)
    {
        return false;
    }

    return true;
}
