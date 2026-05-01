/**
 * @file logger.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-05
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "logger.h"

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
        // Wait for a notification.
        mCondVar.wait(lock);
    
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
    }
}