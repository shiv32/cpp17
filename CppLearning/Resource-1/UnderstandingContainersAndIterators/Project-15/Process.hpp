/**
 * @file Process.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-12-26
 *
 * @copyright Copyright (c) 2024
 *
 */
#pragma once

#include <iostream>

// Simple Process class.
class Process final
{
public:
    // Constructor accepting the name of the process.
    Process(std::string_view name);

    // Implementation of doWorkDuringTimeSlice() would let the process
    // perform its work for the duration of a time slice.
    // Actual implementation omitted.
    void doWorkDuringTimeSlice();

    // Needed for the RoundRobin::remove() method to work.
    bool operator==(const Process &rhs);

private:
    std::string mName;
};