// Thread with Function object

// g++ main.cpp -o test -pthread

#include <iostream>
#include <thread>

class Counter
{
public:
    Counter(int id, int numIterations)
        : mId(id), mNumIterations(numIterations)
    {
    }

    void operator()() const
    {
        for (int i = 0; i < mNumIterations; ++i)
        {
            std::cout << "Counter " << mId << " has value " << i << std::endl;
        }
    }

private:
    int mId;
    int mNumIterations;
};

int main() //thread
{

    // Using uniform initialization syntax
   // std::thread t1{Counter{1, 20}};

    // Using named variable
    //Counter c(2, 12);
   //std::thread t2(c);

    // Using temporary
    std::thread t3(Counter(3, 10));

    // Wait for threads to finish
    //t1.join();
    //t2.join();
   //t3.join();

    return 1;
}