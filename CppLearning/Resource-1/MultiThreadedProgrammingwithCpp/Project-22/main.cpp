/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 *
 *  THREAD POOLS Example 1
 *
 * @version 0.1
 * @date 2025-03-05
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include "ThreadPool.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    ThreadPool pool(4); // Create a thread pool with 4 threads

    // Submit tasks
    auto result1 = pool.enqueue( [] { return "Hello from thread pool!"; } );

    auto result2 = pool.enqueue( [](int a, int b) { return a + b; }, 10, 20 );

    std::cout << result1.get() << std::endl;

    std::cout << "Sum: " << result2.get() << std::endl;

    return 0; // Thread pool destructor is called automatically
}