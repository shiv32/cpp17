/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief inline function vs normal function
 * @version 0.1
 * @date 2024-10-16
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>

inline int square1(int x)
{
    return x * x;
}

int square2(int x)
{
    return x * x;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    int num = 5;

    std::cout << "Square of " << num << " is " << square1(num) << std::endl; // Inline function call
    std::cout << "Square of " << num << " is " << square2(num) << std::endl; // Normal function call

    return 0;
}

//----------------------------------------------------------------------------------------------------------

// #include <iostream>
// #include <chrono> // For timing the function execution

// // Inline function
// inline int add(int x, int y)
// {
//     return x + y;
// }

// // Non-inline function
// int multiply(int x, int y)
// {
//     return x * y;
// }

// int main()
// {

//     system("clear && printf '\e[3J'"); // clean the terminal before output in linux

//     int a = 5, b = 3;
//     const int iterations = 100000000; // Large number of iterations to measure performance

//     // Measure time for inline function
//     auto start_inline = std::chrono::high_resolution_clock::now();
//     int inline_result = 0;
//     for (int i = 0; i < iterations; ++i)
//     {
//         inline_result = add(a, b); // Call inline function
//     }
//     auto end_inline = std::chrono::high_resolution_clock::now();
//     auto inline_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_inline - start_inline);
//     std::cout << "Inline function result: " << inline_result << "\n";
//     std::cout << "Inline function time: " << inline_duration.count() << " microseconds\n";

//     // Measure time for non-inline function
//     auto start_non_inline = std::chrono::high_resolution_clock::now();
//     int non_inline_result = 0;
//     for (int i = 0; i < iterations; ++i)
//     {
//         non_inline_result = multiply(a, b); // Call non-inline function
//     }
//     auto end_non_inline = std::chrono::high_resolution_clock::now();
//     auto non_inline_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_non_inline - start_non_inline);
//     std::cout << "Non-inline function result: " << non_inline_result << "\n";
//     std::cout << "Non-inline function time: " << non_inline_duration.count() << " microseconds\n";

//     return 0;
// }
