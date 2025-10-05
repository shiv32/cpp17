#include <iostream>
#include <stdexcept>
#include <list>

struct Negative_size
{
    const char *what() const noexcept
    {
        return "Size cannot be negative!";
    }
};

template <typename T>
class Vector
{
private:
    T *elem; // elem points to an array of sz elements of type T
    int sz;

public:
    explicit Vector(int s);      // constructor: establish invariant, acquire resources
    ~Vector() { delete[] elem; } // destructor: release resources

    // ... copy and move operations ...

    T &operator[](int i);             // for non-const Vectors
    const T &operator[](int i) const; // for const Vectors (§4.2.1)
    int size() const { return sz; }
};

template <typename T>
Vector<T>::Vector(int s)
{
    if (s < 0)
        throw Negative_size{};

    elem = new T[s];
    sz = s;
}

template <typename T>
T &Vector<T>::operator[](int i)
{
    if (i < 0 || size() <= i)
        throw std::out_of_range{"Vector::operator[]"};

    return elem[i];
}

template <typename T>
const T &Vector<T>::operator[](int i) const
{
    if (i < 0 || size() <= i)
        throw std::out_of_range{"Vector::operator[]"};

    return elem[i];
}

void write(const Vector<std::string> &vs) // Vector of some strings
{
    for (int i = 0; i != vs.size(); ++i)
    {
        std::cout << vs[i] << '\n';
    }
}

template <typename T>
T *begin(Vector<T> &x)
{
    return x.size() ? &x[0] : nullptr; // pointer to first element or nullptr
}

template <typename T>
T *end(Vector<T> &x)
{
    return x.size() ? &x[0] + x.size() : nullptr; // pointer to one-past-last element
}

void f2(Vector<std::string> &vs) // Vector of some strings
{
    for (auto &s : vs)
        std::cout << s << '\n';
}

int main(int argc, char *argv[])
{
    Vector<char> vc(200);           // vector of 200 characters
    Vector<std::string> vs(17);     // vector of 17 strings
    Vector<std::list<int>> vli(45); // vector of 45 lists of integers

    return 0;
}