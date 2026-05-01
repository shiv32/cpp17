/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Thread with Function object

        g++ main.cpp -o test -pthread && ./test && rm test
 *
 *
 * @version 0.1
 * @date 2024-10-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <thread>
#include <functional>

class Counter
{
public:
    Counter()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    Counter(int id, int numIterations)
        : mId(id), mNumIterations(numIterations)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    void operator()() const
    {
        for (int i = 0; i < mNumIterations; ++i)
        {
            std::cout << "Counter " << mId << " has value " << i << std::endl;
        }
    }

private:
    int mId{4};
    int mNumIterations{11};
};

int main() // thread
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Using uniform initialization syntax
    // std::thread t1{Counter{1, 20}};

    // Using named variable
    // Counter c(2, 12);
    // std::thread t2(c);

    // Using temporary
    // std::thread t3(Counter(3, 10));

    // std::thread t4(Counter()); // Error!
    // std::thread t4{Counter{}}; // OK, Using uniform initialization syntax

    Counter c5(2, 12);
    /*
     execute operator() on a specific instance of your function object
     instead of copying it.
    */
    std::thread t5(std::ref(c5)); 

    // Wait for threads to finish
    // t1.join();
    // t2.join();
    // t3.join();
    // t4.join();
    t5.join();

    return 1;
}