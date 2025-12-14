#pragma once
#include <vector>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include "Task.hpp"

class ThreadPool {
public:
    explicit ThreadPool(size_t threads);
    ~ThreadPool();

    void submit(Task task);

private:
    struct TaskCompare {
        bool operator()(const Task& a, const Task& b) {
            return static_cast<int>(a.priority()) <
                   static_cast<int>(b.priority());
        }
    };

    std::vector<std::thread> workers;
    std::priority_queue<Task,
        std::vector<Task>,
        TaskCompare> tasks;

    std::mutex queueMutex;
    std::condition_variable condition;
    std::atomic<bool> stop;
};
