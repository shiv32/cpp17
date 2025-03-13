/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 *
 * Tested on simulIDE & simavr
 *
 * avr-g++ -mmcu=atmega328p -std=c++17 -Os -o main.elf main.cpp && avr-objcopy -O ihex main.elf main.hex
 *
 *
 *
 * @version 0.1
 * @date 2025-03-10
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "mcal_reg.h"
#include <stdint.h>
#include <avr/io.h>        // AVR I/O definitions
#include <avr/interrupt.h> // Enable/disable interrupts
#include <util/delay.h>    // Include delay functions


class led
{

public:
    // Use convenient class-specific typedefs.
    typedef uint8_t port_type;
    typedef uint8_t bval_type;

    led(const port_type p, const bval_type b) : port(p), bval(b)
    {
        // Set the port pin value to low.
        *reinterpret_cast<volatile bval_type *>(port) &= static_cast<bval_type>(~bval);

        // Set the port pin direction to output.
        // Note that the address of the port direction
        // register is one less than the address
        // of the port value register.
        const port_type pdir = port - 1U;

        *reinterpret_cast<volatile bval_type *>(pdir) |= bval;
    }

    void toggle() const
    {
        // Toggle the LED via direct memory access.
        *reinterpret_cast<volatile bval_type *>(port) ^= bval;
    }

private:
    // Private member variables of the class.
    const port_type port;
    const bval_type bval;
};

namespace
{
    // Create led_b5 on portb.5.
    const led led_b5{mcal::reg::portb, mcal::reg::bval5};
}

int main()
{
    //sei(); // Enable global interrupts

    // Toggle led_b5 in a loop forever.
    for (;;)
    {
        led_b5.toggle();
        _delay_ms(1000); // Wait for 1 second (1000 milliseconds)
    }

    return 0;
}
