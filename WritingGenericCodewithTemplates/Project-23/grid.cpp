
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

//Overload operator+ in template
template <typename T>
Grid<T> operator+(const Grid<T> &lhs, const Grid<T> &rhs)
{
    size_t minWidth = std::min(lhs.getWidth(), rhs.getWidth());
    size_t minHeight = std::min(lhs.getHeight(), rhs.getHeight());

    Grid<T> result(minWidth, minHeight); // grid of N X M

    for (size_t y = 0; y < minHeight; ++y)
    {
        for (size_t x = 0; x < minWidth; ++x)
        {
            // when operator+ is no friend
            const auto &leftElement = lhs.at(x, y);
            const auto &rightElement = rhs.at(x, y);

            // when operator+ is friend
            // const auto &leftElement = lhs.mCells[x][y];
            // const auto &rightElement = rhs.mCells[x][y];

            if (leftElement.has_value() && rightElement.has_value())
                result.at(x, y) = leftElement.value() + rightElement.value();
        }
    }
    return result;
}