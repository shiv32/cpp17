#include <iostream>
#include <cstdint>

// Simulated memory array for testing
// The size of the array is specified as 256,
// meaning it can hold 256 individual 8-bit unsigned integers (or bytes).
// Simulated memory buffer with 256 bytes, initialized to 0
std::uint8_t simulated_memory[256] = {0};

constexpr std::uint8_t one = UINT8_C(0b1);
constexpr std::uint8_t seven = UINT8_C(0b0000'0111);

void do_something()
{
    // The address of the portb register.
    constexpr std::uint8_t portb = UINT8_C(0x25);

    std::clog << "portb = " << static_cast<int>(simulated_memory[portb]) << '\n';

    /*
    Embedded C++: You can safely do this because the MCU memory map is fixed and you have direct access.
    Desktop C++: Protected memory model prevents you from touching arbitrary physical addresses.
    */
    // Switch portb.5 from low to high.
    //*reinterpret_cast<volatile std::uint8_t *>(portb) |= UINT8_C(0b0010'0000);
    *reinterpret_cast<volatile std::uint8_t *>(&simulated_memory[portb]) |= UINT8_C(0b0010'0000);

    std::clog << "portb = " << static_cast<int>(simulated_memory[portb]) << '\n';
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Printing uint8_t directly can show as a char.
    // Cast to int so you see the numeric value.
    std::clog << "one = " << static_cast<int>(one) << '\n';
    std::clog << "seven = " << static_cast<int>(seven) << '\n';

    do_something();

    return 0;
}
