#include <iostream>

template <typename T>
class MyClass
{
public:
    void print()
    {
        std::cout << "General template\n";
    }
};

// Full specialization
template <>
class MyClass<int>
{
public:
    void print()
    {
        std::cout << "Specialized for int\n";
    }
};

// Partial specialization for pointer types
template <typename T>
class MyClass<T *>
{
public:
    void print()
    {
        std::cout << "Specialized for pointer type\n";
    }
};

template <typename T>
class Wrapper
{
};

// Specialize for pair types
template <typename T, typename U>
class Wrapper<std::pair<T, U>>
{
public:
    void show()
    {
        std::cout << "Wrapper for pair\n";
    }
};

int main()
{

    MyClass<double> a;
    a.print(); // General template
    MyClass<int> b;
    b.print(); // Specialized for int
    MyClass<int *> c;
    c.print(); // Specialized for pointer types

    Wrapper<std::pair<int, float>> w;
    w.show();
}