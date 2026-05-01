#pragma once

#include <iostream>
#include <stdexcept>
#include "SpreadsheetCell.hpp"
#include <memory>
#include <vector>

class Spreadsheet
{
public:
    Spreadsheet(size_t width, size_t height, std::string sheetname = "");

    /*
    --> If you have dynamically allocated memory in your class.
    --> Implement a destructor, copy constructor, move constructor,
    copy assignment operator, and move assignment operator.
    --> This is called the Rule of Five.
    */
    // Spreadsheet(const Spreadsheet &src);                // Copy constructor
    // Spreadsheet &operator=(const Spreadsheet &rhs);     // Copy assign
    // Spreadsheet(Spreadsheet &&src) noexcept;            // Move constructor
    // Spreadsheet &operator=(Spreadsheet &&rhs) noexcept; // Move assign
    // ~Spreadsheet();                                     // Destructor

    // Disallowing Assignment and Pass-By-Value
    /*
    Spreadsheet(const Spreadsheet &src) = delete;
    Spreadsheet &operator=(const Spreadsheet &rhs) = delete;
    */

    // swapCopy() implementation does not use move semantics.
    template <typename T>
    void swapCopy(T &a, T &b);

    /*
    With move semantics, the implementation can avoid all copying.
    This is exactly how std::swap() from the Standard Library is implemented.
    */
    template <typename T>
    void swapMove(T &a, T &b);

    friend void swap(Spreadsheet &first, Spreadsheet &second) noexcept;

    // void setCellAt(size_t x, size_t y, const SpreadsheetCell &cell);
    void setCellAt(size_t x, size_t y, const std::shared_ptr<SpreadsheetCell> &cell);

    // SpreadsheetCell &getCellAt(size_t x, size_t y);
    std::shared_ptr<SpreadsheetCell> &getCellAt(size_t x, size_t y);
    const std::shared_ptr<SpreadsheetCell>& getCellAt(size_t x, size_t y) const;

    size_t getWidth() const;
    size_t getHeight() const;
    std::string getSheetname() const;

private:
    bool inRange(size_t value, size_t upper) const;
    void verifyCoordinate(size_t x, size_t y) const;
    size_t mWidth = 0;
    size_t mHeight = 0;

    // SpreadsheetCell **mCells = nullptr;
    std::vector<std::vector<std::shared_ptr<SpreadsheetCell>>> mCells;

    std::string sheetName{};
    void cleanup() noexcept;
    void moveFrom(Spreadsheet &src) noexcept;

    Spreadsheet() = default;
};

template <typename T>
inline void Spreadsheet::swapCopy(T &a, T &b)
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl;
    T temp(a);
    a = b;
    b = temp;
}

template <typename T>
inline void Spreadsheet::swapMove(T &a, T &b)
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl;
    T temp(std::move(a));
    a = std::move(b);
    b = std::move(temp);
}