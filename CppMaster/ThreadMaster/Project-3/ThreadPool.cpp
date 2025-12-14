#include "ThreadPool.hpp"
#include <iostream>

ThreadPool::ThreadPool(size_t threads) : stop(false) {
    for (size_t i = 0; i < threads; ++i) {
        workers.emplace_back([this, i] {
            while (true) {
                Task task(0, "", TaskPriority::LOW, []{});

                {
                    std::unique_lock<std::mutex> lock(queueMutex);
                    condition.wait(lock, [this] {
                        return stop || !tasks.empty();
                    });

                    if (stop && tasks.empty())
                        return;

                    task = tasks.top();
                    tasks.pop();
                }

                std::cout << "[Thread " << i
                          << "] Executing task: "
                          << task.name() << "\n";

                task.execute();
            }
        });
    }
}

void ThreadPool::submit(Task task) {
    {
        std::lock_guard<std::mutex> lock(queueMutex);
        tasks.push(std::move(task));
    }
    condition.notify_one();
}

ThreadPool::~ThreadPool() {
    stop = true;
    condition.notify_all();

    for (auto& t : workers)
        t.join();
}
