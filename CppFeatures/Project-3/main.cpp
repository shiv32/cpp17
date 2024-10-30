/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief benchmark inline function vs normal function

   g++ -O2 main.cpp -o main

    -O2 enables a moderate level of optimization.

    Common optimization levels include
     -O0 (no optimization),
     -O2 (optimized code),
     -O3 (aggressive optimization)


    3e-8 in decimal form = 0.00000003


 * @version 0.1
 * @date 2024-10-16
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <chrono>

// Inline function
inline int add_inline(int a, int b)
{
    return a + b;
}

// Non-inline function
int add_non_inline(int a, int b)
{
    return a + b;
}

int main()
{
    // system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    const int iterations = 100000000;
    int result = 0;

    // Measure time for inline function
    auto start_inline = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i)
    {
        result += add_inline(i, i + 1);
    }
    auto end_inline = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_inline = end_inline - start_inline;
    std::cout << "Inline function time: " << duration_inline.count() << " seconds\n";

    result = 0; // Reset result

    // Measure time for non-inline function
    auto start_non_inline = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i)
    {
        result += add_non_inline(i, i + 1);
    }
    auto end_non_inline = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_non_inline = end_non_inline - start_non_inline;
    std::cout << "Non-inline function time: " << duration_non_inline.count() << " seconds\n";

    return 0;
}

//-------------------------------------------------------------------
// #include <iostream>
// #include <chrono>

// inline int add_inline(int a, int b)
// {
//     return a + b;
// }

// int add_non_inline(int a, int b)
// {
//     return a + b;
// }

// int main()
// {

//     system("clear && printf '\e[3J'"); // clean the terminal before output in linux

//     const int iterations = 100000000; // Large number of iterations to get noticeable time
//     int result = 0;

//     // Measure inline function time
//     auto start_inline = std::chrono::high_resolution_clock::now();
//     for (int i = 0; i < iterations; ++i)
//     {
//         result += add_inline(i, i + 1);
//     }
//     auto end_inline = std::chrono::high_resolution_clock::now();
//     std::chrono::duration<double, std::nano> duration_inline = end_inline - start_inline;
//     std::cout << "Inline function time: " << duration_inline.count() / iterations << " ns per call\n";

//     result = 0; // Reset result

//     // Measure non-inline function time
//     auto start_non_inline = std::chrono::high_resolution_clock::now();
//     for (int i = 0; i < iterations; ++i)
//     {
//         result += add_non_inline(i, i + 1);
//     }
//     auto end_non_inline = std::chrono::high_resolution_clock::now();
//     std::chrono::duration<double, std::nano> duration_non_inline = end_non_inline - start_non_inline;
//     std::cout << "Non-inline function time: " << duration_non_inline.count() / iterations << " ns per call\n";

//     return 0;
// }

//-----------------------------------------------------------------------------
// #include <iostream>
// #include <chrono>

// inline int add_inline(int a, int b)
// {
//     return a + b;
// }

// int add_non_inline(int a, int b)
// {
//     return a + b;
// }

// int main()
// {

//     system("clear && printf '\e[3J'"); // clean the terminal before output in linux

//     const int iterations = 100000000;
//     int result = 0;

//     // Measure inline function time
//     auto start_inline = std::chrono::high_resolution_clock::now();

//     for (int i = 0; i < iterations; ++i)
//     {
//         result += add_inline(i, i + 1);
//     }

//     auto end_inline = std::chrono::high_resolution_clock::now();

//     std::chrono::duration<double> duration_inline = end_inline - start_inline;

//     std::cout << "Inline function time: " << duration_inline.count() << " seconds\n";

//     result = 0; // Reset result

//     // Measure non-inline function time
//     auto start_non_inline = std::chrono::high_resolution_clock::now();

//     for (int i = 0; i < iterations; ++i)
//     {
//         result += add_non_inline(i, i + 1);
//     }

//     auto end_non_inline = std::chrono::high_resolution_clock::now();

//     std::chrono::duration<double> duration_non_inline = end_non_inline - start_non_inline;

//     std::cout << "Non-inline function time: " << duration_non_inline.count() << " seconds\n";

//     return 0;
// }

//---------------------------------------------------------------------------------------------------------
// #include <iostream>

// inline int square1(int x)
// {
//     return x * x;
// }

// int square2(int x)
// {
//     return x * x;
// }

// int main()
// {
//     system("clear && printf '\e[3J'"); // clean the terminal before output in linux

//     int num = 5;

//    std::cout << "Square of " << num << " is " << square1(num) << std::endl; // Inline function call
//     //std::cout << "Square of " << num << " is " << square2(num) << std::endl; // Normal function call

//     return 0;
// }

//----------------------------------------------------------------------------------------------------------

// #include <iostream>
// #include <chrono> // For timing the function execution

// // Inline function
// inline int add(int x, int y)
// {
//     return x + y;
// }

//  int add2(int x, int y)
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

//     // auto inline_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_inline - start_inline);
//      auto inline_duration = std::chrono::duration_cast<std::chrono::seconds>(end_inline - start_inline);

//     std::cout << "Inline function result: " << inline_result << "\n";
//     std::cout << "Inline function time: " << inline_duration.count() << " microseconds\n";

//     // Measure time for non-inline function
//     auto start_non_inline = std::chrono::high_resolution_clock::now();

//     int non_inline_result = 0;
//     for (int i = 0; i < iterations; ++i)
//     {
//          non_inline_result = multiply(a, b); // Call non-inline function
//         //non_inline_result = add2(a, b); // Call non-inline function
//     }
//     auto end_non_inline = std::chrono::high_resolution_clock::now();

//     // auto non_inline_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_non_inline - start_non_inline);
//     auto non_inline_duration = std::chrono::duration_cast<std::chrono::seconds>(end_non_inline - start_non_inline);

//     std::cout << "Non-inline function result: " << non_inline_result << "\n";
//     std::cout << "Non-inline function time: " << non_inline_duration.count() << " microseconds\n";

//     return 0;
// }
