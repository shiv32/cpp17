#pragma once

#include <vector>
#include <iostream>
#include <optional>

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

private:
    void verifyCoordinate(size_t x, size_t y) const;

    std::vector<std::vector<std::optional<T>>> mCells;

    size_t mWidth, mHeight;
};
