
template <typename T>
Grid<T>::~Grid()
{
    //std::cout << __PRETTY_FUNCTION__ << std::endl;
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
    //std::cout << __PRETTY_FUNCTION__ << std::endl;
    return const_cast<std::optional<T> &>(std::as_const(*this).at(x, y));
}

//---------------------------------Class Template Specialization-------------------------------------------

Grid<const char *>::Grid(size_t width, size_t height) : mWidth(width), mHeight(height)
{
    std::cout << "---------- Specialization --------" << std::endl;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    
    mCells.resize(mWidth);
    for (auto &column : mCells)
    {
        column.resize(mHeight);
    }
}

void Grid<const char *>::verifyCoordinate(size_t x, size_t y) const
{
    //std::cout << "---------- Specialization --------" << std::endl;
    //std::cout << __PRETTY_FUNCTION__ << std::endl;

    if (x >= mWidth || y >= mHeight)
    {
        throw std::out_of_range("");
    }
}

const std::optional<std::string> &Grid<const char *>::at(size_t x, size_t y) const
{
    //std::cout << "---------- Specialization --------" << std::endl;
    //std::cout << __PRETTY_FUNCTION__ << std::endl;

    verifyCoordinate(x, y);
    return mCells[x][y];
}

std::optional<std::string> &Grid<const char *>::at(size_t x, size_t y)
{
    //std::cout << "---------- Specialization --------" << std::endl;
    //std::cout << __PRETTY_FUNCTION__ << std::endl;

    return const_cast<std::optional<std::string> &>(std::as_const(*this).at(x, y));
}
