#include <iostream>
#include <vector>

// Base template (fallback)
template <typename T>
void func(T value)
{
    std::cout << "Base template\n";
}

// Full specialization
template <>
void func<int>(int value)
{
    std::cout << "Specialized for int: " << value << "\n";
}

// More specific template overload (acts like partial specialization)
template <typename T>
void func(T *value)
{
    std::cout << "Pointer overload\n";
}

// Overload for array types
template <typename T>
void func2(T value)
{
    std::cout << "General type\n";
}
// partial specialization
template <typename T, std::size_t N>
void func2(T (&arr)[N])
{
    std::cout << "Array overload\n";
}

// Overload for std::vector<T>
template <typename T>
void func3(const T &v)
{
    std::cout << "General template\n";
}
// partial specialization
template <typename T>
void func3(const std::vector<T> &v)
{
    std::cout << "Vector overload\n";
}

int main()
{
    // int x = 5;
    // func(8.4); // Base template
    // func(10);  // Specialized template
    // func(&x);  // partial specialization,  Pointer overload

    // int a[10];
    // func2(a);   // Array overload
    // func2(5);   // General type

    func3(42);                     // General template
    func3(std::vector<int>{1, 2}); // Vector overload
}
