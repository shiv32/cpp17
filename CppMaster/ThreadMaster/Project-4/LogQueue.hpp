#pragma once
#include <queue>
#include <string>
#include <mutex>
#include <condition_variable>

class LogQueue
{
public:
    void push(std::string log);
    bool pop(std::string &log);
    void shutdown();

private:
    std::queue<std::string> queue_;
    std::mutex mutex_;
    std::condition_variable cv_;
    bool finished_ = false;
};
