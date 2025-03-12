/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 *
        std::shared_future
        g++ --std=c++17 main.cpp -o test -pthread
 *
 *
 * @version 0.1
 * @date 2025-03-04
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include <future>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::promise<void> thread1Started, thread2Started;
    std::promise<int> signalPromise;

    auto signalFuture = signalPromise.get_future().share();
    // shared_future<int> signalFuture(signalPromise.get_future());

    auto function1 = [&thread1Started, signalFuture]
    {
        std::cout << " thread1Started" << std::endl;

        thread1Started.set_value();

        // Wait until parameter is set.
        int parameter = signalFuture.get();

        std::cout << " thread1Started unblock" << std::endl;
        std::cout << " parameter 1 : " << parameter << std::endl;
    };

    auto function2 = [&thread2Started, signalFuture]
    {
        std::cout << " thread2Started" << std::endl;

        thread2Started.set_value();

        // Wait until parameter is set.
        int parameter = signalFuture.get();

        std::cout << " thread2Started unblock" << std::endl;
        std::cout << " parameter 2 : " << parameter << std::endl;
    };

    // Run both lambda expressions asynchronously.
    // Remember to capture the future returned by async()!
    auto result1 = std::async(std::launch::async, function1);
    auto result2 = std::async(std::launch::async, function2);

    // Wait until both threads have started.
    thread1Started.get_future().wait();
    thread2Started.get_future().wait();

    // Both threads are now waiting for the parameter.
    // Set the parameter to wake up both of them.
    signalPromise.set_value(42);

    return 0;
}