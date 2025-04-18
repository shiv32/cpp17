#pragma once

#include <vector>
#include <iostream>
#include <optional>

template <typename T, size_t WIDTH, size_t HEIGHT>
class Grid
{
public:
    Grid() = default;
    virtual ~Grid() = default;

    // Explicitly default a copy constructor and assignment operator.
    Grid(const Grid &src) = default;
    Grid<T, WIDTH, HEIGHT> &operator=(const Grid &rhs) = default;

    std::optional<T> &at(size_t x, size_t y);
    const std::optional<T> &at(size_t x, size_t y) const;

    size_t getHeight() const { return HEIGHT; }
    size_t getWidth() const { return WIDTH; }

private:
    void verifyCoordinate(size_t x, size_t y) const;
    std::optional<T> mCells[WIDTH][HEIGHT];
};

//------------------------------ template definition -------------------------
#include "grid.cpp"
