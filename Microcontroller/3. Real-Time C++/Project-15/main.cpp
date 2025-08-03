#include <iostream>
#include <cstdint>

constexpr std::uint64_t one_trillion = UINT64_C(1'000'000'000'000);

constexpr long double pi = 3.1415926535'8979323846'2643383279'5028841972L;

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux\

    std::cout << "One trillion: " << one_trillion << '\n';
    std::cout << "Pi: " << pi << '\n';

    return 0;
}
