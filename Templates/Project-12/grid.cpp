


template <typename T, size_t WIDTH, size_t HEIGHT>
Grid<T, WIDTH, HEIGHT>::Grid(const T &data){
   std::cout<<"Template type : " << typeid(T).name() << std::endl;
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
