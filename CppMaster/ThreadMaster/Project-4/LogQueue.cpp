#include "LogQueue.hpp"

void LogQueue::push(std::string log)
{
    {
        std::lock_guard<std::mutex> lock(mutex_);
        queue_.push(std::move(log));
    }
    cv_.notify_one();
}

bool LogQueue::pop(std::string &log)
{
    std::unique_lock<std::mutex> lock(mutex_);
    cv_.wait(lock, [this]
             { return finished_ || !queue_.empty(); });

    if (queue_.empty())
        return false;

    log = std::move(queue_.front());
    queue_.pop();
    return true;
}

void LogQueue::shutdown()
{
    {
        std::lock_guard<std::mutex> lock(mutex_);
        finished_ = true;
    }
    cv_.notify_all();
}
