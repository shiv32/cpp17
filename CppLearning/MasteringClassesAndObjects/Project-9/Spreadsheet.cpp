#include "Spreadsheet.hpp"

Spreadsheet::Spreadsheet(size_t width, size_t height, std::string sheetname)
    : mWidth(width), mHeight(height), sheetName(sheetname)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    mCells = new SpreadsheetCell *[mWidth];

    for (size_t i = 0; i < mWidth; i++)
    {
        mCells[i] = new SpreadsheetCell[mHeight];
    }
}

Spreadsheet::Spreadsheet(const Spreadsheet &src)
    : Spreadsheet(src.mWidth, src.mHeight, src.sheetName)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
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
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    // Check for self-assignment
    if (this == &rhs)
    {
        return *this;
    }
    Spreadsheet temp(rhs); // Do all the work in a temporary instance
    swap(*this, temp);     // Commit the work with only non-throwing operations
    return *this;
}

Spreadsheet::Spreadsheet(Spreadsheet &&src) noexcept
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    // moveFrom(src);

    swap(*this, src);
}

Spreadsheet &Spreadsheet::operator=(Spreadsheet &&rhs) noexcept
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    // check for self-assignment
    /*
     if (this == &rhs)
      {
          return *this;
      }

      // free the old memory
      cleanup();
      moveFrom(rhs);
     */

    Spreadsheet temp(std::move(rhs));
    swap(*this, temp);

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
    mWidth = mHeight = 0;
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

size_t Spreadsheet::getWidth() const { return mWidth; }

size_t Spreadsheet::getHeight() const { return mHeight; }

std::string Spreadsheet::getSheetname() const
{
    return sheetName;
}

void Spreadsheet::verifyCoordinate(size_t x, size_t y) const
{
    if (x >= mWidth || y >= mHeight)
    {
        throw std::out_of_range("");
    }
}

void Spreadsheet::cleanup() noexcept
{
    for (size_t i = 0; i < mWidth; i++)
    {
        delete[] mCells[i];
    }

    delete[] mCells;
    mCells = nullptr;
    mWidth = mHeight = 0;
}

void Spreadsheet::moveFrom(Spreadsheet &src) noexcept
{
    // Move object data members
    sheetName = std::move(src.sheetName);

    // Shallow copy of data
    mWidth = src.mWidth;
    mHeight = src.mHeight;
    mCells = src.mCells;

    // Reset the source object, because ownership has been moved!
    src.mWidth = 0;
    src.mHeight = 0;
    src.mCells = nullptr;
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
    // using std::swap;
    // swap(first.mWidth, second.mWidth);
    // swap(first.mHeight, second.mHeight);
    // swap(first.mCells, second.mCells);

    auto ss = std::make_unique<Spreadsheet>(0,0);
    ss->swapMove(first.mWidth, second.mWidth);
    ss->swapMove(first.mHeight, second.mHeight);
    ss->swapMove(first.mCells, second.mCells);
}
