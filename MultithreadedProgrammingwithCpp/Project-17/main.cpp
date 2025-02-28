/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 *
    std::async
    g++ --std=c++17 main.cpp -o test -pthread
 *
 * @version 0.1
 * @date 2025-03-01
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include <future>

int calculate()
{
    return 123;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    auto myFuture = std::async(calculate);
    // auto myFuture = std::async(std::launch::async, calculate);
    // auto myFuture = std::async(std::launch::deferred, calculate);

    //  Do some more work...
    //  Get the result.

    int result = myFuture.get();
    std::cout << result << std::endl;
}