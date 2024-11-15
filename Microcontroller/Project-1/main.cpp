// The LED program.

#include <iostream>
#include <cstdint>
#include "mcal_reg.h"
#include <thread> // For std::this_thread::sleep_for
#include <chrono> // For std::chrono::seconds

// Simulated memory array for testing
// The size of the array is specified as 256,
// meaning it can hold 256 individual 8-bit unsigned integers (or bytes).
// Simulated memory buffer with 256 bytes, initialized to 0
std::uint8_t simulated_memory[256] = {0};

class led
{
public:
    // Use convenient class-specific typedefs.
    typedef std::uint8_t port_type;
    typedef std::uint8_t bval_type;

    led(const port_type p, const bval_type b) : port(p), bval(b)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;

        // Set the port pin value to low.
        // *reinterpret_cast<volatile bval_type *>(port) &= static_cast<bval_type>(~bval);
        *reinterpret_cast<volatile bval_type *>(&simulated_memory[port]) &= static_cast<bval_type>(~bval);

        // Set the port pin direction to output.
        // Note that the address of the port direction
        // register is one less than the address
        // of the port value register.
        const port_type pdir = port - 1U;

        // *reinterpret_cast<volatile bval_type *>(pdir) |= bval;
        *reinterpret_cast<volatile bval_type *>(&simulated_memory[pdir]) |= bval;
    }

    void toggle() const
    {
        // Toggle the LED via direct memory access.
        // *reinterpret_cast<volatile bval_type *>(port) ^= bval;
        *reinterpret_cast<volatile bval_type *>(&simulated_memory[port]) ^= bval;
    }

    // Print the current state of the port for debugging
    void print_state() const
    {
        std::cout << "Port 0x" << std::hex << static_cast<int>(port)
                  << " state: 0x" << static_cast<int>(simulated_memory[port]) << std::endl;
    }

private:
    // Private member variables of the class.
    const port_type port;
    const bval_type bval;
};

namespace
{
    // Create led_b5 on portb.5.
    const led led_b5
    {
        mcal::reg::portb,
        mcal::reg::bval5
    };
}

// namespace custom
// {
//     // Create led_b5 on portb.5.
//     const led led_b5
//     {
//         mcal::reg::portb,
//         mcal::reg::bval5
//     };
// }

int main()
{
    // system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::cout << __PRETTY_FUNCTION__ << std::endl;

    //------------------------------------------
    // // Initialize Port B to 0
    // simulated_memory[mcal::reg::portb] = 0x00;

    // // Create led_b5 on portb.5.
    // const led led_b5{
    //     mcal::reg::portb,
    //     mcal::reg::bval5};
    //-----------------------------------------------------

    // Toggle led_b5 in a loop forever.
    for (;;)
    {
        led_b5.toggle();
        led_b5.print_state();

        // Sleep for 1 seconds
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}