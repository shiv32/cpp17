// std::packaged_task
// g++ --std=c++17 main.cpp -o test -pthread

#include <iostream>
#include <thread>
#include <future>

int CalculateSum(int a, int b)
{
    return a + b;
}

int main()
{
    // Create a packaged task to run CalculateSum.
    std::packaged_task<int(int, int)> task(CalculateSum);

    // Get the future for the result of the packaged task.
    auto theFuture = task.get_future();

    // Create a thread, move the packaged task into it, and
    // execute the packaged task with the given arguments.
    std::thread theThread{std::move(task), 39, 3};

    // Do some more work...
    // Get the result.
    int result = theFuture.get();
    std::cout << result << std::endl;

    // Make sure to join the thread.
    theThread.join();
}