/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Thread Local Storage

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
#include <mutex> // std::mutex, std::lock_guard

std::mutex sMutex{};
thread_local int n = 0; // Each thread has its own instance of 'n'
int k{};

void increment()
{
    thread_local int n1{}; // Acts as static within each thread

    std::lock_guard lock(sMutex); // c++ 17
    {
        ++n; // Modifying the thread-local variable 'n'
        ++k;
        ++n1;

        std::cout << "Thread ID: " << std::this_thread::get_id() << ", n: " << n << std::endl;
        std::cout << "Thread ID: " << std::this_thread::get_id() << ", k: " << k << std::endl;
        std::cout << "Thread ID: " << std::this_thread::get_id() << ", n1: " << n1 << std::endl;
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::thread t1(increment);
    std::thread t2(increment);

    std::thread t3([](){

        increment();
        increment(); 
        
        });

    t1.join();
    t2.join();
    t3.join();

    return 0;
}