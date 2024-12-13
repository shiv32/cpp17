/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Acquiring Multiple Locks at Once
 *        scoped_lock
 * 
 * @version 0.1
 * @date 2024-10-21
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mut1, mut2;

void process()
{
    // Create but don't lock
    std::unique_lock lock1(mut1, std::defer_lock); // C++17
    std::unique_lock lock2(mut2, std::defer_lock); // C++17

    // unique_lock<mutex> lock1(mut1, defer_lock);
    // unique_lock<mutex> lock2(mut2, defer_lock);

    lock(lock1, lock2);
    // Locks acquired

    std::cout << "process(): Both mutexes are locked by thread " << std::this_thread::get_id() << std::endl;

} // Locks automatically released

void process2()
{
    std::scoped_lock locks(mut1, mut2);
    // Locks acquired

    //std::scoped_lock<std::mutex, std::mutex> locks(mut1, mut2);

    std::cout << "process2(): Both mutexes are locked by thread " << std::this_thread::get_id() << std::endl;

} // Locks automatically released

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // std::thread t1(process);
    // std::thread t2(process);

    std::thread t1(process2);
    std::thread t2(process2);

    t1.join();
    t2.join();

    return 0;
}