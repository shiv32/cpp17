#include "LogQueue.hpp"
#include "LogWorker.hpp"
#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
#include <chrono>

LogWorker::LogWorker(int id, LogQueue &q, std::atomic<int> &count)
    : id_(id), queue_(q), processedCount_(count) {}

void LogWorker::operator()()
{
    std::string log;
    while (queue_.pop(log))
    {
        std::cout << "[Worker " << id_
                  << "] processing: " << log << "\n";
        processedCount_++;
        std::this_thread::sleep_for(
            std::chrono::milliseconds(200));
    }
}

int main()
{
    LogQueue queue;
    std::atomic<int> processed{0};

    std::thread producer([&queue]
                         {
        for (int i = 1; i <= 10; ++i) {
            queue.push("Log entry " + std::to_string(i));
            std::this_thread::sleep_for(
                std::chrono::milliseconds(100));
        }
        queue.shutdown(); });

    std::vector<std::thread> workers;
    for (int i = 0; i < 3; ++i)
    {
        workers.emplace_back(
            LogWorker(i + 1, queue, processed));
    }

    producer.join();
    for (auto &w : workers)
        w.join();

    std::cout << "Total logs processed: "
              << processed << "\n";
}
