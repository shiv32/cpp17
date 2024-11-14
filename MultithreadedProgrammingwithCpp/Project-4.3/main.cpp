/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Retrieving Results from Threads

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
#include <future>

void computeSquare(int x, std::promise<int> resultPromise)
{
    resultPromise.set_value(x * x); // Set the result in the promise
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::promise<int> resultPromise;
    std::future<int> resultFuture = resultPromise.get_future();

    std::thread t(computeSquare, 5, std::move(resultPromise)); // Pass the promise to the thread

    // Retrieve the result from the future
    int square = resultFuture.get(); // This will block until the promise is fulfilled
    
    std::cout << "Square of 5 is: " << square << std::endl;

    t.join();

    return 0;
}