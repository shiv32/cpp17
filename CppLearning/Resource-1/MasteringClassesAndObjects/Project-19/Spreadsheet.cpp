#include "Spreadsheet.hpp"
#include "SpreadsheetApplication.hpp"

// size_t Spreadsheet::sCounter;

// Define the default instance
SpreadsheetApplication defaultApp;

// Function to return a reference to the default instance
SpreadsheetApplication& getDefaultApp() 
{
    return defaultApp;
}

Spreadsheet::Spreadsheet(size_t width, size_t height, std::string sheetname, SpreadsheetApplication& theApp)
    : mId(sCounter++)
    , mWidth(std::min(width, kMaxWidth)) // std::min() requires <algorithm>
    , mHeight(std::min(height, kMaxHeight))
    , sheetName(sheetname)
    , mCells(mWidth, std::vector<std::shared_ptr<SpreadsheetCell>>(mHeight))
    , mTheApp(theApp)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    //----------------- default value at cell (1,1) ----------------------
    auto sc1 = std::make_shared<SpreadsheetCell>(8.98);
    this->setCellAt(1, 1, sc1);
    //---------------------------------------------------------------------

    // mCells = new SpreadsheetCell *[mWidth];

    // for (size_t i = 0; i < mWidth; i++)
    // {
    //     mCells[i] = new SpreadsheetCell[mHeight];
    // }
}

// Spreadsheet::Spreadsheet(const Spreadsheet &src)
//     : Spreadsheet(src.mWidth, src.mHeight, src.sheetName)
// {
//     std::cout << __PRETTY_FUNCTION__ << std::endl;

//     for (size_t i = 0; i < mWidth; i++)
//     {
//         for (size_t j = 0; j < mHeight; j++)
//         {
//             mCells[i][j] = src.mCells[i][j];
//         }
//     }
// }

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
// Spreadsheet &Spreadsheet::operator=(const Spreadsheet &rhs)
// {
//     std::cout << __PRETTY_FUNCTION__ << std::endl;
//     // Check for self-assignment
//     if (this == &rhs)
//     {
//         return *this;
//     }
//     Spreadsheet temp(rhs); // Do all the work in a temporary instance
//     swap(*this, temp);     // Commit the work with only non-throwing operations
//     return *this;
// }

// Spreadsheet::Spreadsheet(Spreadsheet &&src) noexcept
// {
//     std::cout << __PRETTY_FUNCTION__ << std::endl;

//     // moveFrom(src);

//     swap(*this, src);
// }

// Spreadsheet &Spreadsheet::operator=(Spreadsheet &&rhs) noexcept
// {
//     std::cout << __PRETTY_FUNCTION__ << std::endl;

//     // check for self-assignment
//     /*
//      if (this == &rhs)
//       {
//           return *this;
//       }

//       // free the old memory
//       cleanup();
//       moveFrom(rhs);
//      */

//     Spreadsheet temp(std::move(rhs));
//     swap(*this, temp);

//     return *this;
// }

// Spreadsheet::~Spreadsheet()
// {
//     // for (size_t i = 0; i < mWidth; i++)
//     // {
//     //     delete[] mCells[i];
//     // }
//     // delete[] mCells;
//     // mCells = nullptr;
//     // mWidth = mHeight = 0;
// }

// void Spreadsheet::setCellAt(size_t x, size_t y, const SpreadsheetCell &cell)
void Spreadsheet::setCellAt(size_t x, size_t y, const std::shared_ptr<SpreadsheetCell> &cell)
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

std::shared_ptr<SpreadsheetCell> &Spreadsheet::getCellAt(size_t x, size_t y)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    /*
    if (!inRange(x, mWidth) || !inRange(y, mHeight))
    {
        throw std::out_of_range("");
    }
    */

    // verifyCoordinate(x, y);
    // return mCells[x][y];

    // The std::as_const() function is available since C++17.
    return const_cast<std::shared_ptr<SpreadsheetCell> &>(std::as_const(*this).getCellAt(x, y));
    // or
    // return const_cast<std::shared_ptr<SpreadsheetCell>&>(static_cast<const Spreadsheet&>(*this).getCellAt(x, y));
}

const std::shared_ptr<SpreadsheetCell> &Spreadsheet::getCellAt(size_t x, size_t y) const
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    verifyCoordinate(x, y);
    return mCells[x][y];
}

size_t Spreadsheet::getWidth() const { return mWidth; }

size_t Spreadsheet::getHeight() const { return mHeight; }

std::string Spreadsheet::getSheetname() const
{
    return sheetName;
}

std::string Spreadsheet::GetDefaultAppSheetName() const
{
    return mTheApp.DefaultSheetName();
}

size_t Spreadsheet::getId() const
{
    return mId;
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
    // for (size_t i = 0; i < mWidth; i++)
    // {
    //     delete[] mCells[i];
    // }

    // delete[] mCells;
    // mCells = nullptr;
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
    // src.mCells = nullptr;
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

    auto ss = std::make_unique<Spreadsheet>(0, 0);
    ss->swapMove(first.mWidth, second.mWidth);
    ss->swapMove(first.mHeight, second.mHeight);
    ss->swapMove(first.mCells, second.mCells);
}
