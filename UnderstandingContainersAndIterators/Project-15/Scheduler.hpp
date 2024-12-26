/**
 * @file Scheduler.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-12-27
 *
 * @copyright Copyright (c) 2024
 *
 */
#pragma once

#include <vector>
#include "RoundRobin.hpp"
#include "Process.hpp"

// Simple round-robin based process scheduler.
class Scheduler final
{
public:
    // Constructor takes a vector of processes.
    Scheduler(const std::vector<Process> &processes);

    // Selects the next process using a round-robin scheduling
    // algorithm and allows it to perform some work during
    // this time slice.
    void scheduleTimeSlice();

    // Removes the given process from the list of processes.
    void removeProcess(const Process &process);

private:
    RoundRobin<Process> mProcesses;
};