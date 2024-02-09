// Double-Checked Locking
// g++ --std=c++17 main.cpp -o test -pthread

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <atomic>

using namespace std;

void initializeSharedResources()
{
    // ... Initialize shared resources to be used by multiple threads.
    cout << "Shared resources initialized." << endl;
}

atomic<bool> gInitialized(false);
mutex gMutex;

void processingFunction()
{
    if (!gInitialized)
    {
        unique_lock lock(gMutex);

        if (!gInitialized)
        {
            initializeSharedResources();
            gInitialized = true;
        }
    }
    cout << "OK" << endl;
}

int main()
{
    vector<thread> threads;

    for (int i = 0; i < 5; ++i)
    {
        threads.push_back(thread{processingFunction});
    }

    for (auto &t : threads)
    {
        t.join();
    }

    return 0;
}
