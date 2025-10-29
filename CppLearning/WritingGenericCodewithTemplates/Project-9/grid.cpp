#include "grid.hpp"
#include <utility>

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

// Explicit instantiations for the types you want to allow.
template class Grid<int>;
template class Grid<double>;
template class Grid<std::vector<int>>;