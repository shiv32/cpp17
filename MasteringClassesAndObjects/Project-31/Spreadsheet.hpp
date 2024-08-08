#pragma once

#include <iostream>
#include <stdexcept>
#include "SpreadsheetCell.hpp"
#include <memory>
#include <vector>
#include <algorithm>

// Forward declaration of SpreadsheetApplication
class SpreadsheetApplication;

// Function to get a reference to the default SpreadsheetApplication instance
SpreadsheetApplication &getDefaultApp();

class Spreadsheet
{
public:
    Spreadsheet(size_t width = kMaxWidth,
                size_t height = kMaxHeight,
                std::string sheetname = "",
                const SpreadsheetApplication &theApp = getDefaultApp());

     Spreadsheet(const Spreadsheet &src);                // Copy constructor
     Spreadsheet &operator=(const Spreadsheet &rhs);     // Copy assign
    // Spreadsheet(Spreadsheet &&src) noexcept;            // Move constructor
    // Spreadsheet &operator=(Spreadsheet &&rhs) noexcept; // Move assign
     ~Spreadsheet();                                     // Destructor

    friend void swap(Spreadsheet &first, Spreadsheet &second) noexcept;

    void setCellAt(size_t x, size_t y, const std::shared_ptr<SpreadsheetCell> &cell);

    std::shared_ptr<SpreadsheetCell> &getCellAt(size_t x, size_t y);
    const std::shared_ptr<SpreadsheetCell> &getCellAt(size_t x, size_t y) const;

    size_t getWidth() const;
    size_t getHeight() const;

    static inline const size_t kMaxHeight = 100;
    static inline const size_t kMaxWidth = 100;

private:
    size_t mWidth = 0;
    size_t mHeight = 0;
    std::vector<std::vector<std::shared_ptr<SpreadsheetCell>>> mCells;
    std::string sheetName{};

    static inline size_t sCounter;
    const size_t mId = 0;
    const SpreadsheetApplication &mTheApp;

    class Impl;
    std::unique_ptr<Impl> mImpl;
};

class Spreadsheet::Impl
{
  public:
    Impl(size_t width = Spreadsheet::Impl::kMaxWidth,
                size_t height = Spreadsheet::Impl::kMaxHeight,
                std::string sheetname = "",
                const SpreadsheetApplication &theApp = getDefaultApp());

   
     Impl(const Impl &src);                // Copy constructor
     Impl &operator=(const Impl &rhs);     // Copy assign

    // swapCopy() implementation does not use move semantics.
    template <typename T>
    void swapCopy(T &a, T &b);

    /*
    With move semantics, the implementation can avoid all copying.
    This is exactly how std::swap() from the Standard Library is implemented.
    */
    template <typename T>
    void swapMove(T &a, T &b);

    //friend void swap(Spreadsheet &first, Spreadsheet &second) noexcept;
    void swap(Impl& other) noexcept;

    // void setCellAt(size_t x, size_t y, const SpreadsheetCell &cell);
    void setCellAt(size_t x, size_t y, const std::shared_ptr<SpreadsheetCell> &cell);

    // SpreadsheetCell &getCellAt(size_t x, size_t y);
    std::shared_ptr<SpreadsheetCell> &getCellAt(size_t x, size_t y);
    const std::shared_ptr<SpreadsheetCell> &getCellAt(size_t x, size_t y) const;

    size_t getWidth() const;
    size_t getHeight() const;

    static inline const size_t kMaxHeight = 100;
    static inline const size_t kMaxWidth = 100;

private:
    void verifyCoordinate(size_t x, size_t y) const;
    size_t mWidth = 0;
    size_t mHeight = 0;
    std::vector<std::vector<std::shared_ptr<SpreadsheetCell>>> mCells;
    std::string sheetName{};

    static inline size_t sCounter;
    const size_t mId = 0;

    const SpreadsheetApplication &mTheApp;
};

template <typename T>
inline void Spreadsheet::Impl::swapCopy(T &a, T &b)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    T temp(a);
    a = b;
    b = temp;
}

template <typename T>
inline void Spreadsheet::Impl::swapMove(T &a, T &b)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    T temp(std::move(a));
    a = std::move(b);
    b = std::move(temp);
}