/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief

        Atomic Type Example
        g++ main.cpp -o test -pthread && ./test && rm test

 * @version 0.1
 * @date 2024-10-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <atomic>
#include <thread>
#include <chrono>
#include <vector>

using namespace std;

//-----------------(example 1)-------------------------------------

// void increment(int &counter)
// {
//     for (int i = 0; i < 100; ++i)
//     {
//         ++counter;
//         this_thread::sleep_for(1ms);
//     }
// }

// int main()
// {
//     system("clear && printf '\e[3J'"); // clean the terminal before output in linux

//     int counter = 0;

//     std::vector<std::thread> threads;

//     for (int i = 0; i < 10; ++i)
//     {
//         threads.push_back(thread{increment, ref(counter)});
//     }

//     for (auto &t : threads)
//     {
//         t.join();
//     }

//     cout << "Result = " << counter << endl;

//     return 0;
// }

//---------------------------(eaxmple 2)-------------------------------

// void increment(atomic<int> &counter)
// {
//     for (int i = 0; i < 100; ++i)
//     {
//         ++counter;
//         this_thread::sleep_for(1ms);
//     }
// }

// int main()
// {
//     system("clear && printf '\e[3J'"); // clean the terminal before output in linux

//     atomic<int> counter(0);

//     std::vector<std::thread> threads;

//     for (int i = 0; i < 10; ++i)
//     {
//         threads.push_back(thread{increment, ref(counter)});
//     }

//     for (auto &t : threads)
//     {
//         t.join();
//     }

//     cout << "Result = " << counter << endl;

//     return 0;
// }


//----------------------------(example 3 Best and recommended solution)---------------------------------------

void increment(atomic<int> &counter)
{
    int result = 0;

    for (int i = 0; i < 100; ++i)
    {
        ++result;
        this_thread::sleep_for(1ms);
    }
    
    counter += result;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    atomic<int> counter(0);

    std::vector<std::thread> threads;

    for (int i = 0; i < 10; ++i)
    {
        threads.push_back(thread{increment, ref(counter)});
    }

    for (auto &t : threads)
    {
        t.join();
    }

    cout << "Result = " << counter << endl;

    return 0;
}