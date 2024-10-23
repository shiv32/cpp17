/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 
        std::call_once
        g++ main.cpp -o test -pthread && ./test && rm test


 * @version 0.1
 * @date 2024-10-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;

once_flag gOnceFlag;

void initializeSharedResources()
{
    // ... Initialize shared resources to be used by multiple threads.
    cout << "Shared resources initialized." << endl;
}

void processingFunction()
{
    // Make sure the shared resources are initialized.
    call_once(gOnceFlag, initializeSharedResources);

    // ... Do some work, including using the shared resources
    cout << "Processing" << endl;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    
    // Launch 3 threads.
    vector<thread> threads(3);

    for (auto &t : threads)
    {
        t = thread{processingFunction};
    }

    // Join on all threads
    for (auto &t : threads)
    {
        t.join();
    }

    return 0;
}