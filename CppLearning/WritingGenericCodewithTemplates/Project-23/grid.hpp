#pragma once

#include <vector>
#include <iostream>
#include <optional>

// when operator+ is friend ---------------------------
//friend function in C++ can access private and protected members of a class.

// Forward declare Grid template
template <typename T> class Grid;

// Prototype for templatized operator+
template <typename T>
Grid<T> operator+(const Grid<T> &lhs, const Grid<T> &rhs);

//------------------------------------------------------

template <typename T>
class Grid
{
public:
    explicit Grid(size_t width = kDefaultWidth,
                  size_t height = kDefaultHeight);

    virtual ~Grid();

    // Explicitly default a copy constructor and assignment operator.
    Grid(const Grid &src) = default;
    Grid<T> &operator=(const Grid &rhs) = default;

    // Explicitly default a move constructor and assignment operator.
    Grid(Grid &&src) = default;
    Grid<T> &operator=(Grid &&rhs) = default;

    std::optional<T> &at(size_t x, size_t y);
    const std::optional<T> &at(size_t x, size_t y) const;

    size_t getHeight() const { return mHeight; }
    size_t getWidth() const { return mWidth; }

    static const size_t kDefaultWidth = 10;
    static const size_t kDefaultHeight = 10;

    //friend
    friend Grid<T> operator+ <T>(const Grid<T> &lhs, const Grid<T> &rhs);

private:
    void verifyCoordinate(size_t x, size_t y) const;
    std::vector<std::vector<std::optional<T>>> mCells;
    size_t mWidth, mHeight;
};

//------------------------------ template definition -------------------------
#include "grid.cpp"
