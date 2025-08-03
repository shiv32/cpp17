#include <iostream>
#include <atomic>
#include <cstdint>

namespace
{
    // The one (and only one) 32-bit system-tick.
    volatile std::atomic<std::uint32_t> system_tick;
}

std::uint32_t get_time_elapsed()
{
    // Ensure 32-bit consistency on an 8-bit CPU.
    return std::atomic_load(&system_tick);
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::clog << "System Tick: " << get_time_elapsed() << std::endl;

    return 0;
}
