/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 *
        CONDITION VARIABLES
        g++ --std=c++17 main.cpp -o test -pthread
 *
 *
 * @version 0.1
 * @date 2025-02-13
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <memory>

class QueueProcessor
{
private:
    std::queue<int> mQueue;
    std::mutex mMutex;
    std::condition_variable mCondVar;

public:
    void producer()
    {
        std::thread([this]
                    {
            for (int i = 1; i <= 5; ++i) {
                {
                    std::lock_guard<std::mutex> lock(mMutex);
                    mQueue.push(i);
                    std::cout << "Produced: " << i << std::endl;
                }
                mCondVar.notify_one(); // Notify consumer
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
            } })
            .detach();  // Detached so it runs independently
    }

    void consumer()
    {
        std::thread([this]
                    {
            while (true) {
                std::unique_lock<std::mutex> lock(mMutex);
                mCondVar.wait(lock, [this] { return !mQueue.empty(); }); // Using this->mQueue

                int item = mQueue.front();
                mQueue.pop();
                std::cout << "Consumed: " << item << std::endl;

                if (item == 5) break; // Stop condition
            } })
            .detach(); // Detached so it runs independently
    }
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    auto QueuePrsr = std::make_unique<QueueProcessor>();

    QueuePrsr->consumer();
    QueuePrsr->producer();

    std::this_thread::sleep_for(std::chrono::seconds(5)); // Give time for processing

    return 0;
}
