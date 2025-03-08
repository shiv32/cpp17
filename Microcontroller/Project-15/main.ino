/**
 * @file main.ino
 * @author your name (you@domain.com)
 * @brief Tested SimulIDE
 * @version 0.1
 * @date 2025-02-09
 *
 * @copyright Copyright (c) 2025
 *
 */

// The LED program.
#include <stdint.h>
#include <Arduino.h> // Needed for Serial in a custom main()

namespace mcal
{
    // Compile-time constant register addresses.
    namespace reg
    {
        // The address of portb.
        constexpr uint8_t portb = 0x25U;
        
        // The values of bit0 through bit7.
        constexpr uint8_t bval0 = 1U;
        constexpr uint8_t bval1 = 1U << 1U;
        constexpr uint8_t bval2 = 1U << 2U;
        constexpr uint8_t bval3 = 1U << 3U;
        constexpr uint8_t bval4 = 1U << 4U;
        constexpr uint8_t bval5 = 1U << 5U;
        constexpr uint8_t bval6 = 1U << 6U;
        constexpr uint8_t bval7 = 1U << 7U;
    }
}

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

        // Serial.println("Hello from ctor()!");
    }

    void toggle() const
    {
        // Toggle the LED via direct memory access.
        *reinterpret_cast<volatile bval_type *>(port) ^= bval;
        // Serial.println("Hello from toggle()!");
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
    // Serial.begin(9600);
    // while (!Serial); // Wait for Serial Monitor to open

    // while(1)
    for (;;)
    {
        // Serial.println("Hello from main()1!");
        led_b5.toggle();
        _delay_ms(600);

        // Serial.println("Hello from main()2!");
    }

    return 0;
}
