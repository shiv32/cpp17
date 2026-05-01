/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * 
        std::promise and std::future
        g++ --std=c++17 main.cpp -o test -pthread
 * 
 * @version 0.1
 * @date 2025-02-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>
#include <thread>
#include <future>

void DoWork(std::promise<int> thePromise)
{
    // ... Do some work ...
    // And ultimately store the result in the promise.
    thePromise.set_value(42);
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Create a promise to pass to the thread.
    std::promise<int> myPromise;

    // Get the future of the promise.
    auto theFuture = myPromise.get_future();

    // Create a thread and move the promise into it.
    std::thread theThread{DoWork, std::move(myPromise)};

    // Do some more work...
    // Get the result.
    // int result = theFuture.get();
    auto result = theFuture.get();
    
    std::cout << "Result: " << result << std::endl;

    // Make sure to join the thread.
    theThread.join();
}