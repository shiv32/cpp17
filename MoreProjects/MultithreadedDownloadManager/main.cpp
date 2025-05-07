// Multithreaded Download Manager Simulation
// Patterns/Concepts: Threads, Mutex, Condition Variable, Producer-Consumer

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>
#include <string>
#include <vector>
#include <atomic>

// Simulated download task
struct DownloadTask
{
    int id;
    std::string url;
};

class DownloadQueue
{
private:
    std::queue<DownloadTask> tasks;
    std::mutex mtx;
    std::condition_variable cv;
    bool done = false;

public:
    void addTask(const DownloadTask &task)
    {
        {
            std::lock_guard<std::mutex> lock(mtx);
            tasks.push(task);
        }
        cv.notify_one();
    }

    bool getTask(DownloadTask &task)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]
                { return !tasks.empty() || done; });

        if (!tasks.empty())
        {
            task = tasks.front();
            tasks.pop();
            return true;
        }
        return false;
    }

    void finish()
    {
        {
            std::lock_guard<std::mutex> lock(mtx);
            done = true;
        }
        cv.notify_all();
    }
};

class DownloadWorker
{
private:
    int workerId;
    DownloadQueue &queue;
    std::thread workerThread;

public:
    DownloadWorker(int id, DownloadQueue &q) : workerId(id), queue(q) {}

    void start()
    {
        workerThread = std::thread([this]()
                                   {
            DownloadTask task;
            while (queue.getTask(task)) {
                std::cout << "[Worker " << workerId << "] Downloading from: " << task.url << " (Task ID: " << task.id << ")\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                std::cout << "[Worker " << workerId << "] Finished download for Task ID: " << task.id << "\n";
            }
            std::cout << "[Worker " << workerId << "] No more tasks. Exiting.\n"; });
    }

    void join()
    {
        if (workerThread.joinable())
            workerThread.join();
    }
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    DownloadQueue queue;
    std::vector<std::unique_ptr<DownloadWorker>> workers;
    int numWorkers = 3;

    // Create and start workers
    for (int i = 0; i < numWorkers; ++i)
    {
        workers.push_back(std::make_unique<DownloadWorker>(i + 1, queue));
        workers.back()->start();
    }

    // Simulate adding download tasks
    for (int i = 1; i <= 10; ++i)
    {
        queue.addTask({i, "http://example.com/file" + std::to_string(i)});
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }

    // Finish queue and join threads
    queue.finish();

    for (auto &worker : workers)
    {
        worker->join();
    }

    std::cout << "All downloads complete.\n";
    return 0;
}
