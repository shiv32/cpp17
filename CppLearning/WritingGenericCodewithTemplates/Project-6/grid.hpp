#pragma once

#include <vector>
#include <iostream>
#include <optional>
#include <utility>

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

    size_t getHeight() const
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return mHeight;
    }

    size_t getWidth() const
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return mWidth;
    }

    static const size_t kDefaultWidth = 10;
    static const size_t kDefaultHeight = 10;

private:
    void verifyCoordinate(size_t x, size_t y) const;

    std::vector<std::vector<std::optional<T>>> mCells;

    size_t mWidth, mHeight;
};

//------------------------------ template definition -------------------------

template <typename T>
Grid<T>::~Grid()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

template <typename T>
Grid<T>::Grid(size_t width, size_t height)
    : mWidth(width), mHeight(height)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    mCells.resize(mWidth);
    for (auto &column : mCells)
    {
        // Equivalent to:
        // for (std::vector<std::optional<T>>& column : mCells) {
        column.resize(mHeight);
    }
}

template <typename T>
void Grid<T>::verifyCoordinate(size_t x, size_t y) const
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    
    if (x >= mWidth || y >= mHeight)
    {
        throw std::out_of_range("");
    }
}

template <typename T>
const std::optional<T> &Grid<T>::at(size_t x, size_t y) const
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    verifyCoordinate(x, y);
    return mCells[x][y];
}

template <typename T>
std::optional<T> &Grid<T>::at(size_t x, size_t y)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    return const_cast<std::optional<T> &>(std::as_const(*this).at(x, y));
}