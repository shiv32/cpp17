#include <iostream>
#include <algorithm>
#include <array>
#include <cstdint>

namespace
{
    // Four counters.
    std::array<std::uint8_t, 4U> counters;
}

void do_something()
{
    // (Re-)Initialize the counters with std::fill().
    std::fill(counters.begin(), counters.end(), static_cast<std::uint8_t>(0U));

    // Do something with the counters.
    for (const auto &counter : counters)
    {
        std::cout << static_cast<int>(counter) << ", ";
    };

    // std::cout << "\nDone printing\n";
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    do_something();

    return 0;
}
