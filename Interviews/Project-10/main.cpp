#include <iostream>
#include <string>

// 1. Function template
template <typename T>
T add(T a, T b)
{
    return a + b;
}

// 2. Class template
template <typename T>
class Box
{
    T value;

public:
    Box(T v) : value(v) {}
    void show() const { std::cout << "Value: " << value << "\n"; }
};

// 3. Template specialization
template <>
class Box<std::string>
{
    std::string value;

public:
    Box(std::string v) : value(std::move(v)) {}
    void show() const { std::cout << "String value: \"" << value << "\"\n"; }
};

// 4. Non-type template parameter
template <typename T, int Size>
class Array
{
    T data[Size];

public:
    void set(int index, T value) { data[index] = value; }
    void print() const
    {
        for (int i = 0; i < Size; ++i)
        {
            std::cout << data[i] << " ";
        }
        std::cout << "\n";
    }
};

// 5. Template with auto (C++17 deduction guides)
template <typename T1, typename T2>
auto multiply(T1 a, T2 b)
{
    return a * b;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    
    // Function template
    std::cout << "add<int>(3, 4) = " << add<int>(3, 4) << "\n";
    std::cout << "add<double>(2.5, 3.7) = " << add(2.5, 3.7) << "\n"; // type deduced

    // Class template
    Box<int> intBox(42);
    intBox.show();

    // Template specialization
    Box<std::string> strBox("Hello Templates");
    strBox.show();

    // Non-type template parameter
    Array<int, 5> arr;
    for (int i = 0; i < 5; ++i)
        arr.set(i, i * 10);
    arr.print();

    // Template with auto return type
    std::cout << "multiply(3, 4.5) = " << multiply(3, 4.5) << "\n";

    return 0;
}
