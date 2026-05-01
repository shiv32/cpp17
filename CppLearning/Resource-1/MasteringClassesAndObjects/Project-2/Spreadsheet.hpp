#pragma once

#include <stdexcept>
#include "SpreadsheetCell.hpp"

class Spreadsheet
{
public:
    Spreadsheet(size_t width, size_t height);
    ~Spreadsheet();
    void setCellAt(size_t x, size_t y, const SpreadsheetCell &cell);
    SpreadsheetCell &getCellAt(size_t x, size_t y);

private:
    bool inRange(size_t value, size_t upper) const;
    void verifyCoordinate(size_t x, size_t y) const;
    size_t mWidth = 0;
    size_t mHeight = 0;
    SpreadsheetCell **mCells = nullptr;
};