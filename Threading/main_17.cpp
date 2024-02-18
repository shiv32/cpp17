// std::async
// g++ --std=c++17 main.cpp -o test -pthread

#include <iostream>
#include <future>

int calculate()
{
    return 123;
}

int main()
{
    // auto myFuture = std::async(calculate);
    // auto myFuture = std::async(std::launch::async, calculate);
    auto myFuture = std::async(std::launch::deferred, calculate);

    //  Do some more work...
    //  Get the result.

    int result = myFuture.get();
    std::cout << result << std::endl;
}