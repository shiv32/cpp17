/**
 * @file Scheduler.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-12-27
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Scheduler.hpp"
#include <iostream>

Scheduler::Scheduler(const std::vector<Process> &processes)
{
    // Add the processes
    for (auto &process : processes)
    {
        mProcesses.add(process);
    }
}

void Scheduler::scheduleTimeSlice()
{
    try
    {
        mProcesses.getNext().doWorkDuringTimeSlice();
    }
    catch (const std::out_of_range &)
    {
        std::cerr << "No more processes to schedule." << std::endl;
    }
}

void Scheduler::removeProcess(const Process &process)
{
    mProcesses.remove(process);
}
