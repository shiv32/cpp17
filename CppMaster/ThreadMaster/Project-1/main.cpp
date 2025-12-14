#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <mutex>

std::atomic<bool> running{false};
std::thread worker;
std::mutex coutMutex;

void backgroundTask()
{
    while (running)
    {
        {
            std::lock_guard<std::mutex> lock(coutMutex);
            std::cout << "[Thread] Running...\n";
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    {
        std::lock_guard<std::mutex> lock(coutMutex);
        std::cout << "[Thread] Exiting.\n";
    }
}

void startThread()
{
    if (!running)
    {
        running = true;
        worker = std::thread(backgroundTask);
        std::lock_guard<std::mutex> lock(coutMutex);
        std::cout << "[Main] Thread started.\n";
    }
    else
    {
        std::lock_guard<std::mutex> lock(coutMutex);
        std::cout << "[Main] Thread already running.\n";
    }
}

void stopThread()
{
    if (running)
    {
        running = false;
        if (worker.joinable())
            worker.join();
        std::lock_guard<std::mutex> lock(coutMutex);
        std::cout << "[Main] Thread stopped.\n";
    }
    else
    {
        std::lock_guard<std::mutex> lock(coutMutex);
        std::cout << "[Main] Thread not running.\n";
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    
    std::string cmd;
    std::cout << "Commands: start | stop | exit\n";

    while (true)
    {
        {
            std::lock_guard<std::mutex> lock(coutMutex);
            std::cout << "> ";
        }
        std::cin >> cmd;

        if (cmd == "start")
        {
            startThread();
        }
        else if (cmd == "stop")
        {
            stopThread();
        }
        else if (cmd == "exit")
        {
            stopThread();
            break;
        }
        else
        {
            std::lock_guard<std::mutex> lock(coutMutex);
            std::cout << "[Main] Unknown command.\n";
        }
    }

    return 0;
}
