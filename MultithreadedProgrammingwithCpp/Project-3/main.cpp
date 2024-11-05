/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Thread with Lambda

            g++ main.cpp -o test -pthread && ./test && rm test
 *
 * @version 0.1
 * @date 2024-10-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <thread>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    int id = 1;
    int numIterations = 5;

    std::thread t1([id, numIterations]
                   {
                            for (int i = 0; i < numIterations; ++i) {
                            std::cout << "Counter " << id << " has value " << i << std::endl;
                            } 
                    }

                  );

    t1.join();
}