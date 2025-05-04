/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief gprof (GNU Profiler) test

 * @version 0.1
 * @date 2024-10-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <chrono>
#include <thread>

void slow_function()
{
    for (volatile int i = 0; i < 100000000; ++i)
        ; // Burn CPU cycles
}

void fast_function()
{
    for (volatile int i = 0; i < 1000000; ++i)
        ; // Less CPU usage
}

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    slow_function();
    fast_function();

    return 0;
}