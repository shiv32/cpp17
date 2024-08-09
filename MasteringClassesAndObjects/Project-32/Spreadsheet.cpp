#include "Spreadsheet.hpp"
#include "SpreadsheetApplication.hpp"

// size_t Spreadsheet::sCounter;

// Define the default instance
SpreadsheetApplication defaultApp;

// Function to return a reference to the default instance
SpreadsheetApplication &getDefaultApp()
{
    return defaultApp;
}

Spreadsheet::Spreadsheet(size_t width, size_t height, std::string sheetname, const SpreadsheetApplication &theApp)
    : mId(sCounter++), mWidth(std::min(width, kMaxWidth)) // std::min() requires <algorithm>
      ,
      mHeight(std::min(height, kMaxHeight)), sheetName(sheetname), mCells(mWidth, std::vector<std::shared_ptr<SpreadsheetCell>>(mHeight)), mTheApp(theApp)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    // //----------------- default value at cell (1,1) ----------------------
    auto sc1 = std::make_shared<SpreadsheetCell>(8.98);
    this->setCellAt(1, 1, sc1);
    // //---------------------------------------------------------------------
}

Spreadsheet::Spreadsheet(const Spreadsheet &src) : Spreadsheet(src.mWidth, src.mHeight, src.sheetName)
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

Spreadsheet &Spreadsheet::operator=(const Spreadsheet &rhs)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    // Check for self-assignment
    if (this == &rhs)
    {
        return *this;
    }

    Spreadsheet temp(rhs); // Do all the work in a temporary instance
    swap(temp);     // Commit the work with only non-throwing operations
    return *this;
}

Spreadsheet::~Spreadsheet() = default;

void Spreadsheet::swap(Spreadsheet &other) noexcept
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    using std::swap;
    swap(mWidth, other.mWidth);
    swap(mHeight, other.mHeight);
    swap(mCells, other.mCells);
}

void Spreadsheet::setCellAt(size_t x, size_t y, const std::shared_ptr<SpreadsheetCell> &cell)
{
    verifyCoordinate(x, y);
    mCells[x][y] = cell;
}

std::shared_ptr<SpreadsheetCell> &Spreadsheet::getCellAt(size_t x, size_t y)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

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

size_t Spreadsheet::getWidth() const
{
    return mWidth;
}

size_t Spreadsheet::getHeight() const
{
    return mHeight;
}

void Spreadsheet::verifyCoordinate(size_t x, size_t y) const
{
    if (x >= mWidth || y >= mHeight)
    {
        throw std::out_of_range("");
    }
}