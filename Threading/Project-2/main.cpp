/*

MULTITHREADED LOGGER CLASS V-1.0.1

g++ -std=c++17  *.cpp -o test -pthread

*/

#include "logger.h"
#include <sstream>
#include <vector>

void logSomeMessages(int id, Logger &logger)
{
    for (int i = 0; i < 10; ++i)
    {
        std::stringstream ss;
        ss << "Log entry " << i << " from thread " << id;

        logger.log(ss.str());
    }
}

int main()
{
    Logger logger;
    std::vector<std::thread> threads;

    // Create a few threads all working with the same Logger instance.
    for (int i = 0; i < 10; ++i)
    {
        threads.emplace_back(logSomeMessages, i, std::ref(logger));
    }
    
    // Wait for all threads to finish.
    for (auto &t : threads)
    {
        t.join();
    }
}