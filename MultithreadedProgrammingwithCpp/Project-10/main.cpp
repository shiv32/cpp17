/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 *
    Thread-Safe Writing to Streams

    g++ --std=c++17 main.cpp -o test -pthread
 *
 *
 * @version 0.1
 * @date 2024-12-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream> // std::cout
#include <thread>   // std::thread
#include <mutex>    // std::mutex, std::lock_guard

using namespace std;

class Counter
{
public:
    Counter(int id, int numIterations) : mId(id), mNumIterations(numIterations)
    {
    }

    void operator()() const
    {
        for (int i = 0; i < mNumIterations; ++i)
        {
            std::lock_guard lock(sMutex); // c++ 17
            // std::lock_guard<mutex> lck(sMutex);

            cout << "Counter " << mId << " has value " << i << endl;
        }
    }

private:
    int mId;
    int mNumIterations;
    static mutex sMutex;
};

mutex Counter::sMutex{};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::thread t1(Counter(3, 10));

    t1.join();

    return 0;
}