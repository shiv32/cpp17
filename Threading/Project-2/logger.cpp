#include "logger.h"
using namespace std::chrono_literals;

Logger::Logger()
{
    // Start background thread.
    mThread = std::thread{&Logger::processEntries, this};
}
void Logger::log(std::string_view entry)
{
    // Lock mutex and add entry to the queue.
    std::unique_lock lock(mMutex);
    mQueue.push(std::string(entry));
    // Notify condition variable to wake up thread.
    mCondVar.notify_all();
}

void Logger::processEntries()
{
    // Open log file.
    std::ofstream logFile("log.txt");

    if (logFile.fail())
    {
        std::cerr << "Failed to open logfile." << std::endl;
        return;
    }

    // Start processing loop.
    std::unique_lock lock(mMutex);

    while (true)
    {
        /*
        to test that the race condition with the destructor is solved, you can remove any
        calls to log() from the main program, causing it to almost immediately call the destructor of the
        Logger class.
        */
        // std::this_thread::sleep_for(1000ms);

        if (!mExit)
        { // Only wait for notifications if we don't have to exit.
            // Wait for a notification.
            mCondVar.wait(lock);
        }

        // Condition variable notified, something might be in the queue.
        lock.unlock();

        while (true)
        {
            lock.lock();
            if (mQueue.empty())
            {
                break;
            }
            else
            {
                logFile << mQueue.front() << std::endl;
                mQueue.pop();
            }
            lock.unlock();
        }
        if (mExit)
        {
            break;
        }
    }
}

Logger::~Logger()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    {
        std::unique_lock lock(mMutex);

        // Gracefully shut down the thread by setting mExit
        // to true and notifying the thread.
        mExit = true;

        // Notify condition variable to wake up thread.
        mCondVar.notify_all();
    }
    // Wait until thread is shut down. This should be outside the above code
    // block because the lock must be released before calling join()!
    mThread.join();
}