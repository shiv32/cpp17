#pragma once
#include "LogQueue.hpp"
#include <atomic>

class LogWorker
{
public:
    LogWorker(int id, LogQueue &queue, std::atomic<int> &count);
    void operator()();

private:
    int id_;
    LogQueue &queue_;
    std::atomic<int> &processedCount_;
};
