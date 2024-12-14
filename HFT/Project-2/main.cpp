/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Latency Measurement
 * @version 0.1
 * @date 2024-12-14
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <chrono>
#include <thread>

class LatencyTimer
{
public:
    using Clock = std::chrono::high_resolution_clock;
    using TimePoint = std::chrono::time_point<Clock>;

    static TimePoint startTimer()
    {
        return Clock::now();
    }

    static void endTimer(const TimePoint &start, const std::string &operation)
    {
        auto end = Clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        std::cout << operation << " latency: " << duration << " ns" << std::endl;
    }
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    auto start = LatencyTimer::startTimer();

    // Simulate an operation
    std::this_thread::sleep_for(std::chrono::microseconds(100));

    LatencyTimer::endTimer(start, "Operation");

    return 0;
}
