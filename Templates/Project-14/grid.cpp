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
    verifyCoordinate(x, y);
    return mCells[x][y];
}

template <typename T>
std::optional<T> &Grid<T>::at(size_t x, size_t y)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    return const_cast<std::optional<T> &>(std::as_const(*this).at(x, y));
}

template <typename T>
template <typename E>
Grid<T>::Grid(const Grid<E> &src)
    : Grid(src.getWidth(), src.getHeight())
{
    // The ctor-initializer of this constructor delegates first to the
    // non-copy constructor to allocate the proper amount of memory.
    // The next step is to copy the data.
    for (size_t i = 0; i < mWidth; i++)
    {
        for (size_t j = 0; j < mHeight; j++)
        {
            mCells[i][j] = src.at(i, j);
        }
    }
}

template <typename T>
template <typename E>
Grid<T> &Grid<T>::operator=(const Grid<E> &rhs)
{
    // no need to check for self-assignment because this version of
    // assignment is never called when T and E are the same
    // Copy-and-swap idiom
    Grid<T> temp(rhs); // Do all the work in a temporary instance
    swap(temp);        // Commit the work with only non-throwing operations
    return *this;
}

template <typename T>
void Grid<T>::swap(Grid<T> &other) noexcept
{
    using std::swap;
    swap(mWidth, other.mWidth);
    swap(mHeight, other.mHeight);
    swap(mCells, other.mCells);
}