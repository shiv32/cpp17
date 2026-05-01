#include <iostream>
#include <vector>

template <typename T>
class OneDGrid
{
public:
    explicit OneDGrid(size_t size = kDefaultSize);
    virtual ~OneDGrid() = default;

    //It returns a reference to the element at index x.
    T &operator[](size_t x);
    const T &operator[](size_t x) const;

    void resize(size_t newSize);
    size_t getSize() const { return mElements.size(); }

    static const size_t kDefaultSize = 10;

private:
    std::vector<T> mElements;
};

//--------- Definition -----------------
template <typename T>
OneDGrid<T>::OneDGrid(size_t size)
{
    resize(size);
}

template <typename T>
void OneDGrid<T>::resize(size_t newSize)
{
    mElements.resize(newSize);
}

//It returns a reference to the element at index x.
template <typename T>
T &OneDGrid<T>::operator[](size_t x)
{
    //std::clog << __PRETTY_FUNCTION__ << std::endl;
    return mElements[x];
}

template <typename T>
const T &OneDGrid<T>::operator[](size_t x) const
{
    //std::clog << __PRETTY_FUNCTION__ << std::endl;
    return mElements[x];
}