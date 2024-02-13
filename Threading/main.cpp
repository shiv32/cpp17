// std::promise and std::future
// g++ --std=c++17 main.cpp -o test -pthread

#include <iostream>
#include <thread>
#include <future>

void DoWork(std::promise<int> thePromise)
{
    // ... Do some work ...
    // And ultimately store the result in the promise.
    thePromise.set_value(42);
}
int main()
{
    // Create a promise to pass to the thread.
    std::promise<int> myPromise;

    // Get the future of the promise.
    auto theFuture = myPromise.get_future();
    
    // Create a thread and move the promise into it.
    std::thread theThread{DoWork, std::move(myPromise)};
    
    // Do some more work...
    // Get the result.
    int result = theFuture.get();
    std::cout << "Result: " << result << std::endl;
    
    // Make sure to join the thread.
    theThread.join();
}
