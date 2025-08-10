#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

// Simple function
void helloThread()
{
    std::cout << "Hello from thread!\n";
}

// Function with arguments
void printNumbers(int start, int end)
{
    for (int i = start; i <= end; ++i)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

// Function modifying passed variable
void incrementValue(int &val)
{
    for (int i = 0; i < 5; ++i)
    {
        ++val;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // 1. Basic thread creation and join
    std::thread t1(helloThread);
    t1.join(); // wait for t1 to finish

    // 2. Thread with arguments
    std::thread t2(printNumbers, 1, 5);
    t2.join();

    // 3. Thread with reference argument (std::ref)
    int counter = 0;
    std::thread t3(incrementValue, std::ref(counter));
    t3.join();
    std::cout << "Counter after increment: " << counter << "\n";

    // 4. Detached thread
    std::thread t4([]
                   {
        std::cout << "Detached thread starting...\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Detached thread done!\n"; });
    t4.detach();

    // 5. Multiple threads in a loop
    std::vector<std::thread> threads;
    for (int i = 0; i < 3; ++i)
    {
        threads.emplace_back([i]
                             {
            std::cout << "Thread #" << i << " working\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(200)); });
    }
    for (auto &t : threads)
    {
        t.join();
    }

    // Give detached thread time to finish
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Main thread exiting\n";

    return 0;
}
