/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Cancelling Threads

            g++ main.cpp -o test -pthread && ./test && rm test
 *
 *
 * @version 0.1
 * @date 2024-10-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>

std::atomic<bool> stop_flag(false); // Flag to signal the thread to stop

void threadFunction()
{
    std::cout << "threadFunction Thread ID: " << std::this_thread::get_id() << std::endl;

    while (!stop_flag)
    { // Continuously check the stop flag
        // Do some work
        std::cout << std::this_thread::get_id() << " Thread running..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    std::cout << "Thread stopping..." << std::endl;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::cout << "main Thread ID: " << std::this_thread::get_id() << std::endl;

    std::thread worker(threadFunction);

    // Let the worker thread run for a while; main thread sleep
    std::cout << "main thread " << std::this_thread::get_id() << " going to sleep." << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "main thread " << std::this_thread::get_id() << " woke up!" << std::endl;

    // Signal the thread to stop
    stop_flag = true;

    worker.join(); // Wait for the worker thread to finish

    std::cout << "Worker thread has stopped." << std::endl;

    return 0;
}