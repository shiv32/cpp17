// Using Timed Locks
// g++ --std=c++17 main.cpp -o test -pthread

#include <iostream> // std::cout
#include <thread>   // std::thread
#include <mutex>    // std::mutex, std::lock_guard

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
            unique_lock lock(sTimedMutex, 200ms); //c++ 17

            if (lock)
            {
                cout << "Counter " << mId << " has value " << i << endl;
            }
            else
            {
                // Lock not acquired in 200ms, skip output.
            }
        }
    }

private:
    int mId;
    int mNumIterations;
    static timed_mutex sTimedMutex;
};

timed_mutex Counter::sTimedMutex;

int main()
{
    std::thread t1(Counter(3, 10));

    t1.join();

    return 0;
}