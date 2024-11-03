/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief THREADS
            Thread with Function Pointer

            output of the example can be mixed together as follows:

            Counter Counter 2 has value 0
            1 has value 0
            Counter 1 has value 1
            Counter 1 has value 2
            ...
            
            This can be fixed using synchronization methods.

            g++ main.cpp -o test -pthread && ./test && rm test

 * @version 0.1
 * @date 2024-10-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <thread>

void counter(int id, int numIterations)
{
    for (int i = 0; i < numIterations; ++i)
    {
        std::cout << "Counter " << id << " has value " << i << std::endl;
    }
}

int main() // thread
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::thread t1(counter, 1, 6);
    std::thread t2(counter, 2, 4);

    t1.join();
    t2.join();

    return 1;
}