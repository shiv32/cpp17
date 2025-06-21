#include "app/led.hpp"
#include <iostream>

led::led(const port_type p, const bval_type b)
    : port(p), bval(b)
{
    // Set pin low
    *reinterpret_cast<volatile bval_type *>(port) &= static_cast<bval_type>(~bval);

    // Set pin direction to output (port - 1)
    const port_type pdir = port - 1U;
    *reinterpret_cast<volatile bval_type *>(pdir) |= bval;
}

void led::toggle() const
{
    *reinterpret_cast<volatile bval_type *>(port) ^= bval;
    uart_print("Hello, AVR this is shiv Hello from toggle() !\n");
}

void uart_print(const std::string &str)
{
    std::cout << "[UART] " << str;
}
