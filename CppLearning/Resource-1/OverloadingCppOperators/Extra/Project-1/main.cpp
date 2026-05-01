#include <iostream>
#include <bitset>
#include <cstdint>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Bitwise Operators (work on bits)
    uint8_t a = 0b1100'1100; // 204
    uint8_t b = 0b1010'1010; // 170

    std::cout << "a & b  = " << std::bitset<8>(a & b) << "\n";  // 1000'1000
    std::cout << "a | b  = " << std::bitset<8>(a | b) << "\n";  // 1110'1110
    std::cout << "a ^ b  = " << std::bitset<8>(a ^ b) << "\n";  // 0110'0110
    std::cout << "~a     = " << std::bitset<8>(~a) << "\n";     // 0011'0011
    std::cout << "a << 1 = " << std::bitset<8>(a << 1) << "\n"; // 1001'1000
    std::cout << "a >> 1 = " << std::bitset<8>(a >> 1) << "\n"; // 0110'0110

    // Binary Logical Operators (work on bool)
    bool x = true;
    bool y = false;

    std::cout << std::boolalpha;
    std::cout << "x && y = " << (x && y) << "\n"; // false
    std::cout << "x || y = " << (x || y) << "\n"; // true
    std::cout << "!x     = " << (!x) << "\n";     // false
}
