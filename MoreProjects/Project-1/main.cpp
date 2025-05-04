/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief  Task Scheduler written in C++17
 * @version 0.1
 * @date 2025-05-04
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>
#include <functional>
#include <chrono>
#include <thread>
#include <vector>
#include <atomic>
#include <mutex>

class TaskScheduler
{
public:
    using Task = std::function<void()>;

    TaskScheduler() : running(true) {}

    ~TaskScheduler()
    {
        stop();
    }

    void schedule(Task task, std::chrono::milliseconds interval)
    {
        std::lock_guard<std::mutex> lock(mutex_);

        threads.emplace_back([this, task, interval]()
                             {
                                 while (running)
                                 {
                                     auto next_run = std::chrono::steady_clock::now() + interval;
                                     task();
                                     std::this_thread::sleep_until(next_run);
                                 } });
    }

    void stop()
    {
        running = false;

        for (auto &t : threads)
        {
            if (t.joinable())
                t.join();
        }

        threads.clear();
    }

private:
    std::vector<std::thread> threads;
    std::atomic<bool> running;
    std::mutex mutex_;
};

// Example tasks
void printTime()
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::cout << "Current Time: " << std::ctime(&now_time);
}

void printHello()
{
    std::cout << "Hello from TaskScheduler!\n";
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    TaskScheduler scheduler;

    // Schedule tasks
    scheduler.schedule(printTime, std::chrono::seconds(2));
    scheduler.schedule(printHello, std::chrono::seconds(3));

    std::cout << "Press Enter to exit...\n";
    std::cin.get();

    scheduler.stop(); // Stop all tasks
    std::cout << "Scheduler stopped.\n";

    return 0;
}
