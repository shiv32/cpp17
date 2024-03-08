
template <typename T, size_t WIDTH, size_t HEIGHT>
Grid<T, WIDTH, HEIGHT>::Grid(const T &data)
{
    std::cout << "Template type : " << typeid(T).name() << std::endl;
}

template <typename T, size_t WIDTH, size_t HEIGHT>
void Grid<T, WIDTH, HEIGHT>::verifyCoordinate(size_t x, size_t y) const
{
    if (x >= WIDTH || y >= HEIGHT)
    {
        throw std::out_of_range("");
    }
}

template <typename T, size_t WIDTH, size_t HEIGHT>
const std::optional<T> &Grid<T, WIDTH, HEIGHT>::at(size_t x, size_t y) const
{
    verifyCoordinate(x, y);
    return mCells[x][y];
}

template <typename T, size_t WIDTH, size_t HEIGHT>
std::optional<T> &Grid<T, WIDTH, HEIGHT>::at(size_t x, size_t y)
{
    return const_cast<std::optional<T> &>(std::as_const(*this).at(x, y));
}

template <typename T, size_t WIDTH, size_t HEIGHT>
template <typename E, size_t WIDTH2, size_t HEIGHT2>
Grid<T, WIDTH, HEIGHT>::Grid(const Grid<E, WIDTH2, HEIGHT2> &src)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    std::cout << "Template type : " << typeid(T).name() << std::endl;
    std::cout << "WIDTH2 : " << WIDTH2 << std::endl;
    std::cout << "HEIGHT2 : " << HEIGHT2 << std::endl;

    for (size_t i = 0; i < WIDTH; i++)
    {
        for (size_t j = 0; j < HEIGHT; j++)
        {
            if (i < WIDTH2 && j < HEIGHT2)
            {
                mCells[i][j] = src.at(i, j);
            }
            else
            {
                mCells[i][j].reset();
            }
        }
    }
}

template <typename T, size_t WIDTH, size_t HEIGHT>
void Grid<T, WIDTH, HEIGHT>::swap(Grid<T, WIDTH, HEIGHT> &other) noexcept
{
    using std::swap;
    swap(mCells, other.mCells);
}

template <typename T, size_t WIDTH, size_t HEIGHT>
template <typename E, size_t WIDTH2, size_t HEIGHT2>
Grid<T, WIDTH, HEIGHT> &Grid<T, WIDTH, HEIGHT>::operator=(const Grid<E, WIDTH2, HEIGHT2> &rhs)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    std::cout << "Template type : " << typeid(T).name() << std::endl;
    std::cout << "WIDTH2 : " << WIDTH2 << std::endl;
    std::cout << "HEIGHT2 : " << HEIGHT2 << std::endl;

    // no need to check for self-assignment because this version of
    // assignment is never called when T and E are the same
    // Copy-and-swap idiom
    Grid<T, WIDTH, HEIGHT> temp(rhs); // Do all the work in a temp instance
    swap(temp);                       // Commit the work with only non-throwing operations
    return *this;
}