#pragma once

#include <vector>
#include <iostream>
#include <optional>

template <typename T = int, size_t WIDTH = 10, size_t HEIGHT = 10>
class Grid
{
public:
    Grid() = default;
    virtual ~Grid() = default;
    explicit Grid(const T &data);

    // Explicitly default a copy constructor and assignment operator.
    // Grid(const Grid &src) = default;
    // Grid<T, WIDTH, HEIGHT> &operator=(const Grid &rhs) = default;

    template <typename E, size_t WIDTH2, size_t HEIGHT2>
    Grid(const Grid<E, WIDTH2, HEIGHT2> &src);

    template <typename E, size_t WIDTH2, size_t HEIGHT2>
    Grid<T, WIDTH, HEIGHT> &operator=(const Grid<E, WIDTH2, HEIGHT2> &rhs);

    void swap(Grid &other) noexcept;

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
