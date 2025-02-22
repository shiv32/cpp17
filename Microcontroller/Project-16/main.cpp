/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * 
 * `int8_t` and `uint8_t` are fixed-width integer types defined in `<cstdint>` (or `<stdint.h>` in C) 
 * to ensure portability across different platforms.  
 * 
 * @version 0.1
 * @date 2025-02-22
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>

int main() // thread
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    /*
      int8_t (Signed 8-bit Integer)
      Range: (-128) to (127) ((-2^7) to (2^7 - 1))
    */

    // int8_t num = -100; // Valid range: -128 to 127
    // int8_t num1 = 128; // Valid range: -128 to 127
    int8_t num1 = -129; // Valid range: -128 to 127
    std::cout << "Signed 8-bit integer: " << static_cast<int>(num1) << std::endl;

    /*
    uint8_t (Unsigned 8-bit Integer)
    Range: (0) to (255) ((2^8 - 1))
  */
    // uint8_t num2 = 200; // Valid range: 0 to 255
    uint8_t num2 = 256; // Valid range: 0 to 255
    std::cout << "Unsigned 8-bit integer: " << static_cast<int>(num2) << std::endl;

    return 1;
}