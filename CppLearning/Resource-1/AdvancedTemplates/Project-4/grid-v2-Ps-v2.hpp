#include "grid-v2.hpp"

namespace gridv2
{
    //-------------- Partial speciliazation ---------------------
    template <typename T>
    class Grid<T *>
    {
    public:
        explicit Grid(size_t width = kDefaultWidth,
                      size_t height = kDefaultHeight);
        virtual ~Grid() = default;

        // Copy constructor and copy assignment operator.
        Grid(const Grid &src);
        Grid<T *> &operator=(const Grid &rhs);

        // Explicitly default a move constructor and assignment operator.
        Grid(Grid &&src) = default;
        Grid<T *> &operator=(Grid &&rhs) = default;

        void swap(Grid &other) noexcept;

        std::unique_ptr<T> &at(size_t x, size_t y);
        const std::unique_ptr<T> &at(size_t x, size_t y) const;

        size_t getHeight() const { return mHeight; }
        size_t getWidth() const { return mWidth; }

        static const size_t kDefaultWidth = 10;
        static const size_t kDefaultHeight = 10;

    private:
        void verifyCoordinate(size_t x, size_t y) const;
        std::vector<std::vector<std::unique_ptr<T>>> mCells;
        // size_t mWidth = 0, mHeight = 0;
        size_t mWidth{}, mHeight{};
    };

    //------- Definition ----------------------------------------------
    template <typename T>
    Grid<T *>::Grid(size_t width, size_t height) : mWidth(width), mHeight(height)
    {
        std::cout << "Partial speciliazation" << std::endl;
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
    Grid<T *>::Grid(const Grid &src) : Grid(src.mWidth, src.mHeight)
    {
        // The ctor-initializer of this constructor delegates first to the
        // non-copy constructor to allocate the proper amount of memory.

        // The next step is to copy the data.
        for (size_t i = 0; i < mWidth; i++)
        {
            for (size_t j = 0; j < mHeight; j++)
            {
                // Make a deep copy of the element by using its copy constructor.
                if (src.mCells[i][j])
                {
                    mCells[i][j].reset(new T(*(src.mCells[i][j])));
                }
            }
        }
    }

    template <typename T>
    Grid<T *> &Grid<T *>::operator=(const Grid &rhs)
    {
        if (this != &rhs)
        {
            // Resize if needed
            mWidth = rhs.mWidth;
            mHeight = rhs.mHeight;

            mCells.resize(mWidth);
            for (size_t i = 0; i < mWidth; ++i)
                mCells[i].resize(mHeight);

            // Deep copy each cell
            for (size_t i = 0; i < mWidth; i++)
            {
                for (size_t j = 0; j < mHeight; j++)
                {
                    if (rhs.mCells[i][j])
                    {
                        // Create new object via copy-constructor
                        mCells[i][j] = std::make_unique<T>(*(rhs.mCells[i][j]));
                    }
                    // else
                    // {
                    //     // null stays null
                    //     // mCells[i][j].reset();
                    // }
                }
            }
        }

        return *this;
    }

    // template <typename T>
    // Grid<T *>::~Grid()
    // {
    //     std::cout << __PRETTY_FUNCTION__ << std::endl;
    // }

    template <typename T>
    void Grid<T *>::verifyCoordinate(size_t x, size_t y) const
    {
        if (x >= mWidth || y >= mHeight)
        {
            throw std::out_of_range("");
        }
    }

    template <typename T>
    const std::unique_ptr<T> &Grid<T *>::at(size_t x, size_t y) const
    {
        // std::cout << __PRETTY_FUNCTION__ << std::endl;
        verifyCoordinate(x, y);
        return mCells[x][y];
    }

    template <typename T>
    std::unique_ptr<T> &Grid<T *>::at(size_t x, size_t y)
    {
        // std::cout << __PRETTY_FUNCTION__ << std::endl;
        return const_cast<std::unique_ptr<T> &>(std::as_const(*this).at(x, y));
    }
}