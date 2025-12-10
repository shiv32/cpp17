#pragma once

#include "grid-v1.hpp"

namespace gridv1
{
    //-------- Partial Specialization ---------------------
    template <size_t WIDTH, size_t HEIGHT>
    class Grid<const char *, WIDTH, HEIGHT>
    {
    public:
        // Grid() = default;
        Grid()
        {
            std::clog <<"Partial Specialization"<< std::endl;
            std::clog << __PRETTY_FUNCTION__ << std::endl;
        }

        virtual ~Grid() = default;

        // Explicitly default a copy constructor and assignment operator.
        Grid(const Grid &src) = default;
        Grid &operator=(const Grid &rhs) = default;

        std::optional<std::string> &at(size_t x, size_t y);
        const std::optional<std::string> &at(size_t x, size_t y) const;

        size_t getHeight() const { return HEIGHT; }
        size_t getWidth() const { return WIDTH; }

    private:
        void verifyCoordinate(size_t x, size_t y) const;
        std::optional<std::string> mCells[WIDTH][HEIGHT];
    };

    //------- Definition Partial specialization ---------------
    template <size_t WIDTH, size_t HEIGHT>
    void Grid<const char *, WIDTH, HEIGHT>::verifyCoordinate(size_t x, size_t y) const
    {
        if (x >= WIDTH || y >= HEIGHT)
        {
            throw std::out_of_range("");
        }
    }

    template <size_t WIDTH, size_t HEIGHT>
    const std::optional<std::string> &Grid<const char *, WIDTH, HEIGHT>::at(size_t x, size_t y) const
    {
        verifyCoordinate(x, y);
        return mCells[x][y];
    }

    template <size_t WIDTH, size_t HEIGHT>
    std::optional<std::string> &Grid<const char *, WIDTH, HEIGHT>::at(size_t x, size_t y)
    {
        return const_cast<std::optional<std::string> &>(std::as_const(*this).at(x, y));
    }
}