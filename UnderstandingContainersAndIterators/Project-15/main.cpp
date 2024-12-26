/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief vector Example: A Round-Robin Class
 *
 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <vector>
#include "Scheduler.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::vector<Process> processes = {Process("1"), Process("2"), Process("3")};

    Scheduler scheduler(processes);

    for (int i = 0; i < 4; ++i)
        scheduler.scheduleTimeSlice();

    scheduler.removeProcess(processes[1]);

    std::cout << "Removed second process" << std::endl;

    for (int i = 0; i < 4; ++i)
        scheduler.scheduleTimeSlice();

    return 0;
}