/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 *
        CONDITION VARIABLES
        g++ --std=c++17 main.cpp -o test -pthread
 *
 *
 * @version 0.1
 * @date 2025-02-13
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

std::queue<std::string> mQueue;
std::mutex mMutex;
std::condition_variable mCondVar;

void ThreadF_1()
{
    std::unique_lock lock(mMutex);

    std::cout << "Thread 1: Acquired lock" << std::endl;

    while (true)
    {
        // Wait for a notification.
        mCondVar.wait(lock, []
                      { return !mQueue.empty(); });

        // Condition variable is notified, so something is in the queue.
        // Process queue item...
        std::cout << "Thread 1: Received notification : " << mQueue.front() << std::endl;
    }
}

void ThreadF_2(std::string entry)
{
    // Lock mutex and add entry to the queue.
    std::unique_lock lock(mMutex);

    std::cout << "Thread 2: Acquired lock" << std::endl;

    mQueue.push(entry);

    // Notify condition variable to wake up thread.
    mCondVar.notify_all();

    std::cout << "Thread 2: Released lock and notified" << std::endl;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Create threads
    std::thread t1(ThreadF_1);
    std::thread t2(ThreadF_2, "Hello shiv");

    // Join threads
    t1.join();
    t2.join();

    std::cout << "All threads finished" << std::endl;

    return 0;
}
