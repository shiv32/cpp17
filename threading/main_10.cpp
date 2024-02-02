// Thread-Safe Writing to Streams
// g++ --std=c++17 main.cpp -o test -pthread

#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex, std::lock_guard

using namespace std;

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
             std::lock_guard lock(sMutex);  //c++ 17 
            //std::lock_guard<mutex> lck(sMutex); 
            cout << "Counter " << mId << " has value " << i << endl;
        }
    }

private:
    int mId;
    int mNumIterations;
    static mutex sMutex;
};

mutex Counter::sMutex{};

int main()
{
    std::thread t1(Counter(3, 10));

    t1.join();

    return 0;
}