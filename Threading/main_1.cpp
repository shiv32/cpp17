// Thread with Function Pointer
// g++ main.cpp -o test -pthread

#include <iostream>
#include <thread>

void counter(int id, int numIterations)
{
    for (int i = 0; i < numIterations; ++i)
    {
        std::cout << "Counter " << id << " has value " << i << std::endl;
    }
}

int main() //thread
{

    // std::cout<<"Hello Shiv"<<std::endl;

    std::thread t1(counter, 1, 6);
    std::thread t2(counter, 2, 4);

    t1.join();
    t2.join();

    return 1;
}