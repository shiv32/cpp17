#include <iostream>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    constexpr unsigned int version = 3U;

    // Print an error if version is less than 2.
    static_assert(version >= 2U, "Version is too low!");

    // print the version
    std::cout << "Version: " << version << std::endl;

    return 0;
}
