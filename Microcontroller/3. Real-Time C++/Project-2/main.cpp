#include <iostream>
#include <cstdint>

// This has *exactly* 16-bits signed.
constexpr std::int16_t value16 = INT16_C(0x7FFF);

// This has *at least* 32-bits unsigned.
constexpr std::uint_least32_t value32 = UINT32_C(4294967295);

// The suffix U means unsigned int.
//constexpr std::uint32_t prime_664999 = 10006721U;

// Initialize the 664,999th prime number.
// Macros like UINT32_C() are portable.
constexpr std::uint32_t prime_664999 = UINT32_C(10006721);

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::clog<<"value16 : "<<value16<<std::endl;
    std::clog<<"value32 : "<<value32<<std::endl;
    std::clog<<"prime_664999 : "<<prime_664999<<std::endl;

    return 0;
}
