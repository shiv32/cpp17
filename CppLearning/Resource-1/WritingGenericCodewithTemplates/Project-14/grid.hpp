#pragma once

#include <vector>
#include <iostream>
#include <optional>

template <typename T>
class Grid
{
public:
    explicit Grid(size_t width = kDefaultWidth, size_t height = kDefaultHeight);
    virtual ~Grid();

    //-------------------------(Method templates)-----------------------------------------------
    /*
        Templatized versions of the copy constructor and assignment operator to the Grid class
        to generate methods that will convert from one grid type to another.
    */

    // This twofold templatization allows you to copy grids of one type to another.
    template <typename E>
    Grid(const Grid<E> &src);

    template <typename E>
    Grid<T> &operator=(const Grid<E> &rhs);
    //-------------------------------------------------------------------------------------------

    void swap(Grid &other) noexcept;

    // Explicitly default a move constructor and assignment operator.
    Grid(Grid &&src) = default;
    Grid<T> &operator=(Grid &&rhs) = default;

    std::optional<T> &at(size_t x, size_t y);
    const std::optional<T> &at(size_t x, size_t y) const;

    size_t getHeight() const { return mHeight; }
    size_t getWidth() const { return mWidth; }

    static const size_t kDefaultWidth = 10;
    static const size_t kDefaultHeight = 10;

private:
    void verifyCoordinate(size_t x, size_t y) const;
    std::vector<std::vector<std::optional<T>>> mCells;
    size_t mWidth, mHeight;
};

//------------------------------ template definition -------------------------
#include "grid.cpp"
