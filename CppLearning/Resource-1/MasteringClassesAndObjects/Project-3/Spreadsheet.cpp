#include "Spreadsheet.hpp"

Spreadsheet::Spreadsheet(size_t width, size_t height)
    : mWidth(width), mHeight(height)
{
    mCells = new SpreadsheetCell *[mWidth];

    for (size_t i = 0; i < mWidth; i++)
    {
        mCells[i] = new SpreadsheetCell[mHeight];
    }
}

Spreadsheet::Spreadsheet(const Spreadsheet &src)
    : Spreadsheet(src.mWidth, src.mHeight)
{
    for (size_t i = 0; i < mWidth; i++)
    {
        for (size_t j = 0; j < mHeight; j++)
        {
            mCells[i][j] = src.mCells[i][j];
        }
    }
}

/*
naive implementation
This code is not exception safe!
*/
// Spreadsheet &Spreadsheet::operator=(const Spreadsheet &rhs)
// {
//     // Check for self-assignment
//     if (this == &rhs)
//     {
//         return *this;
//     }

//     // Free the old memory
//     for (size_t i = 0; i < mWidth; i++)
//     {
//         delete[] mCells[i];
//     }
//     delete[] mCells;
//     mCells = nullptr;

//     // Allocate new memory
//     mWidth = rhs.mWidth;
//     mHeight = rhs.mHeight;
//     mCells = new SpreadsheetCell *[mWidth];
//     for (size_t i = 0; i < mWidth; i++)
//     {
//         mCells[i] = new SpreadsheetCell[mHeight];
//     }

//     // Copy the data
//     for (size_t i = 0; i < mWidth; i++)
//     {
//         for (size_t j = 0; j < mHeight; j++)
//         {
//             mCells[i][j] = rhs.mCells[i][j];
//         }
//     }
//     return *this;
// }

/*
exception-safe assignment operator.
the copy-and-swap idiom is recommended
*/
Spreadsheet &Spreadsheet::operator=(const Spreadsheet &rhs)
{
    // Check for self-assignment
    if (this == &rhs)
    {
        return *this;
    }
    Spreadsheet temp(rhs); // Do all the work in a temporary instance
    swap(*this, temp);     // Commit the work with only non-throwing operations
    return *this;
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

size_t Spreadsheet::getWidth() { return mWidth; }

size_t Spreadsheet::getHeight() { return mHeight; }

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

void swap(Spreadsheet &first, Spreadsheet &second) noexcept
{
    using std::swap;
    swap(first.mWidth, second.mWidth);
    swap(first.mHeight, second.mHeight);
    swap(first.mCells, second.mCells);
}