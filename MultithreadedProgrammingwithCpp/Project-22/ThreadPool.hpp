/**
 * @file ThreadPool.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-07
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <future>

class ThreadPool
{
public:
    explicit ThreadPool(size_t numThreads);
    ~ThreadPool();

    // Add new task to the queue
    template <class F, class... Args>
    auto enqueue(F &&f, Args &&...args) -> std::future<decltype(f(args...))>;

private:
    std::vector<std::thread> workers;        // Worker threads
    std::queue<std::function<void()>> tasks; // Task queue

    std::mutex queueMutex;
    std::condition_variable condition;
    bool stop;
};

// Constructor: Create worker threads
ThreadPool::ThreadPool(size_t numThreads) : stop(false)
{
    for (size_t i = 0; i < numThreads; ++i)
    {
        workers.emplace_back([this]
                             {
            while (true) {
                std::function<void()> task;
                {
                    std::unique_lock<std::mutex> lock(this->queueMutex);
                    this->condition.wait(lock, [this] { return this->stop || !this->tasks.empty(); });

                    if (this->stop && this->tasks.empty())
                        return; // Exit thread

                    task = std::move(this->tasks.front());
                    this->tasks.pop();
                }
                task(); // Execute the task
            } });
    }
}

// Destructor: Join all threads
ThreadPool::~ThreadPool()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    {
        std::unique_lock<std::mutex> lock(queueMutex);
        stop = true;
    }

    condition.notify_all(); // Wake up all threads

    for (std::thread &worker : workers)
        worker.join(); // Wait for all threads to finish
}

// Add new tasks to the queue
template <class F, class... Args>
auto ThreadPool::enqueue(F &&f, Args &&...args) -> std::future<decltype(f(args...))>
{
    using return_type = decltype(f(args...));

    auto task = std::make_shared<std::packaged_task<return_type()>>(std::bind(std::forward<F>(f), std::forward<Args>(args)...));

    std::future<return_type> res = task->get_future();
    {
        std::unique_lock<std::mutex> lock(queueMutex);
        tasks.emplace([task]()
                      { (*task)(); });
    }

    condition.notify_one(); // Notify one thread to process task

    return res;
}