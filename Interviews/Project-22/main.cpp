
#include <iostream>

template <typename T>
void func(T value)
{
    std::cout << "Primary template: " << value << "\n";
}

// Full specialization
template <>
void func<int>(int value)
{
    std::cout << "Specialized for int: " << value << "\n";
}

// Simulating Partial Specialization using a Class Template
template <typename T>
struct FuncHelper
{
    static void run(T value)
    {
        std::cout << "Primary helper\n";
    }
};

template <typename T>
struct FuncHelper<T *>
{
    static void run(T *value)
    {
        std::cout << "Pointer specialization\n";
    }
};

// Function template dispatches to helper
template <typename T>
void func2(T value)
{
    FuncHelper<T>::run(value);
}

int main()
{
    func(3.14); // Primary template
    func(10);   // Specialized version for int

    int x = 5;
    func2(10); // Primary helper
    func2(&x); // Pointer specialization
}
