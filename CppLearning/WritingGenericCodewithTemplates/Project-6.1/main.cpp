/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Template Requirements on Types
 * @version 0.1
 * @date 2025-03-29
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include <type_traits>

// Implicit Requirements (Duck Typing)
template <typename T>
void printDouble(const T &value)
{
    std::cout << value * 2 << std::endl; // Assumes T supports `operator*`
}

// std::enable_if (SFINAE)
// Enable only if T is an arithmetic type (int, float, double, etc.)
// The = 0 means the second template parameter is optional and doesn't need to be specified explicitly.
// You can replace int with float, double, long, etc., based on your preference. However,
// it’s usually kept as int because it's simple, doesn't cause precision issues, and is universally valid.
template <typename T, typename std::enable_if<std::is_arithmetic<T>::value, int>::type = 0>
void printSquare(const T &value)
{
    std::cout << (value * value) << std::endl;
}

// Type Traits (std::is_integral, std::is_same)
template <typename T>
void checkType()
{
    if constexpr (std::is_integral<T>::value)
    {
        std::cout << "T is an integer type.\n";
    }
    else if constexpr (std::is_floating_point<T>::value)
    {
        std::cout << "T is a floating-point type.\n";
    }
    else
    {
        std::cout << "T is neither integer nor floating point.\n";
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Implicit Requirements (Duck Typing)
    // printDouble(5);    // Works (int supports `operator*`)
    // printDouble(3.14); // Works (double supports `operator*`)
    // printDouble("Hi"); //Compilation error: `operator*` not defined for strings

    // std::enable_if (SFINAE)
    // printSquare(5);   // Works (int is arithmetic)
    // printSquare(2.5); // Works (double is arithmetic)
    // printSquare("Hi"); //Error: std::enable_if prevents this instantiation

    // Type Traits
    //checkType<int>();         // Output: T is an integer type.
    // checkType<double>();      // Output: T is a floating-point type.
     checkType<std::string>(); // Output: T is neither integer nor floating point.

    return 0;
}