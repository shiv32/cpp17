#include "ThreadPool.hpp"
#include <iostream>
#include <chrono>
#include <thread>

int main()
{
    ThreadPool pool(3);

    pool.submit(Task(1, "Low priority task",
                     TaskPriority::LOW, []
                     {
            std::this_thread::sleep_for(
                std::chrono::milliseconds(500));
            std::cout << "Low priority done\n"; }));

    pool.submit(Task(2, "High priority task",
                     TaskPriority::HIGH, []
                     { std::cout << "High priority done\n"; }));

    pool.submit(Task(3, "Medium priority task",
                     TaskPriority::MEDIUM, []
                     { std::cout << "Medium priority done\n"; }));

    return 0;
}
