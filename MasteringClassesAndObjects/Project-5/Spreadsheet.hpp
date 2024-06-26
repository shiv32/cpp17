#pragma once

#include <iostream>
#include <stdexcept>
#include "SpreadsheetCell.hpp"

class Spreadsheet
{
public:
    Spreadsheet(size_t width, size_t height);

    /*
    --> If you have dynamically allocated memory in your class.
    --> Implement a destructor, copy constructor, move constructor,
    copy assignment operator, and move assignment operator.
    --> This is called the Rule of Five.
    */
    Spreadsheet(const Spreadsheet &src);                // Copy constructor
    Spreadsheet &operator=(const Spreadsheet &rhs);     // Copy assign
    Spreadsheet(Spreadsheet &&src) noexcept;            // Move constructor
    Spreadsheet &operator=(Spreadsheet &&rhs) noexcept; // Move assign
    ~Spreadsheet();                                     // Destructor

    // Disallowing Assignment and Pass-By-Value
    /*
    Spreadsheet(const Spreadsheet &src) = delete;
    Spreadsheet &operator=(const Spreadsheet &rhs) = delete;
    */

    friend void swap(Spreadsheet &first, Spreadsheet &second) noexcept;
    void setCellAt(size_t x, size_t y, const SpreadsheetCell &cell);
    SpreadsheetCell &getCellAt(size_t x, size_t y);
    size_t getWidth();
    size_t getHeight();

private:
    bool inRange(size_t value, size_t upper) const;
    void verifyCoordinate(size_t x, size_t y) const;
    size_t mWidth = 0;
    size_t mHeight = 0;
    SpreadsheetCell **mCells = nullptr;

    void cleanup() noexcept;
    void moveFrom(Spreadsheet &src) noexcept;
};