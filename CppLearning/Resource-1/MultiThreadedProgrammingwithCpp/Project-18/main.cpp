/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 *
    Exception Handling std::async
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
    throw std::runtime_error("Exception thrown from calculate().");
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Use the launch::async policy to force asynchronous execution.
    auto myFuture = std::async(std::launch::async, calculate);

    // Do some more work...

    // Get the result.
    try
    {
        int result = myFuture.get();
        std::cout << result << std::endl;
    }
    catch (const std::exception &ex)
    {
        std::cout << "Caught exception: " << ex.what() << std::endl;
    }

    return 0;
}