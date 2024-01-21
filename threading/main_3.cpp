// Thread with Lambda

// g++ main.cpp -o test -pthread

#include <iostream>
#include <thread>

int main()
{
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