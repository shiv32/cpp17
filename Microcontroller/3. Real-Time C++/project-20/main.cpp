#include <iostream>
#include <algorithm>
#include <array>
#include <cstdint>

// Traditional typedef.
typedef unsigned int uint_type;

// C++11 alias.
using uint_type_alias = unsigned int;

void do_something()
{
    // Alias for unsigned int.
    using uint_type = unsigned int;

    // Alias for array of uint_type.
    using array_type = std::array<uint_type, 3U>;

    // Alias for reverse iterator of array of uint_type.
    using reverse_iterator_type = array_type::const_reverse_iterator;

    constexpr array_type my_array({{1U, 2U, 3U}});

    // Find result is 2.
    const reverse_iterator_type ri = std::find(my_array.crbegin(), my_array.crend(), 2U);

    if (ri != my_array.crend())
        std::clog << "Found: " << *ri << "\n";
    else
        std::clog << "Not found." << "\n";
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    do_something();

    return 0;
}
