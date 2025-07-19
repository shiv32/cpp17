#include <iostream>
#include <array>

// A compile-time constant function of low complexity.
constexpr int three()
{
    return 3;
}

struct version_information
{
    // A compile-time constant member variable.
    static constexpr unsigned version = 3U;
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // A compile-time constant version number.
    constexpr unsigned int version = 3U;

    std::clog<< "Version: " << version << '\n';
    std::clog<< "Version: " << version_information::version << '\n';

    // A compile-time floating-point value.
    constexpr float pi = 3.1415926535'8979323846F;
    std::clog<< "Pi: " << pi << '\n';

    std::clog<< "Three(): " << three() << '\n';

    // A constant array of integers.
    constexpr std::array<int, 3U> my_array
                                            {
                                                {1, 2, 3}
                                            };

    std::clog<< "Array: ";
    for (const auto& elem : my_array)
    {
        std::clog << elem << ' ';
    }
    std::clog << '\n';

    return 0;
}
