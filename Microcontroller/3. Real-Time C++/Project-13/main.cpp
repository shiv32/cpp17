#include <iostream>
#include <array>
#include <numeric>

const std::array<int, 3U> u{{1, 2, 3}};
const std::array<int, 3U> v{{4, 5, 6}};

// computes the inner product of two arrays.
const int uv = std::inner_product(u.begin(), u.end(), v.begin(), 0);

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::clog << "uv: " << uv << std::endl;

    return 0;
}
