/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 *
 *  THREAD POOLS Example 2
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
    std::mutex coutMutex; // Global mutex for console output

    ThreadPool pool(4);

    for (int i = 0; i < 8; ++i)
    {
        pool.enqueue([i, &coutMutex]
                     {
                         std::lock_guard<std::mutex> lock(coutMutex);
                         std::cout << "Task " << i << " executed by thread " << std::this_thread::get_id() << "\n"; 
                     });
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));

    return 0; // Thread pool destructor is called automatically
}