/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief volatile uintptr_t
 * @version 0.1
 * @date 2025-03-10
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include <cstdint>

// #define HW_REG_ADDRESS 0x40000000 //DMA not allowed in Desktop PC

//  Simulated memory space
uint32_t fake_memory_region = 0; // address in ram can be accessed
// Simulated memory-mapped address
#define HW_REG_ADDRESS reinterpret_cast<uintptr_t>(&fake_memory_region)

// Simulated hardware register pointer
volatile uint32_t *const hw_reg = reinterpret_cast<volatile uint32_t *>(HW_REG_ADDRESS);

void write_to_register(uint32_t value)
{
    *hw_reg = value; // Write will not be optimized away
}

uint32_t read_from_register()
{
    return *hw_reg; // Always reads fresh value from hardware
}

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    //------------------------------
    int x = 42;
    int *ptr = &x;

    uintptr_t addr = reinterpret_cast<uintptr_t>(ptr); // pointer(ptr) → integer(addr)

    std::cout << "Address as integer x : " << x << '\n';
    std::cout << "Address as integer &x : " << &x << '\n';
    std::cout << "Address as integer ptr : " << ptr << '\n';
    std::cout << "Address as integer *ptr : " << *ptr << '\n';
    std::cout << "Address as integer addr : " << addr << '\n';
    std::cout << "Address as integer: 0x" << std::hex << addr << '\n'; // sets output to hexadecimal

    std::cout << std::dec; // sets output back to decimal (base 10)

    int *back = reinterpret_cast<int *>(addr);       // integer(addr) → pointer(back)
    std::cout << "Value  *back : " << *back << '\n'; // prints 42
    std::cout << "Value  back : " << back << '\n';

    //------------------------------
    write_to_register(45);
    auto value = read_from_register();
    std::cout << "Register value: " << value << std::endl;

    return 0;
}
