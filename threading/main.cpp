// Atomic Type Example
// g++ main.cpp -o test -pthread

#include <iostream>
#include <atomic>
#include <thread>
#include <chrono>
#include <vector>

using namespace std;

// example 1
/*
void increment(int &counter)
{

    for (int i = 0; i < 100; ++i)
    {
        ++counter;
        this_thread::sleep_for(1ms);
    }
}

int main()
{
    int counter = 0;

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

*/

// eaxmple 2
/*
void increment(atomic<int> &counter)
{
    for (int i = 0; i < 100; ++i)
    {
        ++counter;
        this_thread::sleep_for(1ms);
    }
}

int main()
{
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
*/

// example 3

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