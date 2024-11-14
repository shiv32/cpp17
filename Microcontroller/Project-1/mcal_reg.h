#ifndef MCAL_REG_H
#define MCAL_REG_H

#include <cstdint>

namespace mcal
{
    namespace reg
    {

        // Define port types and bit mask types explicitly as 8-bit
        using port_type = std::uint8_t;
        using bval_type = std::uint8_t;

        // Example: Define addresses or constants for 8-bit registers
        constexpr port_type portb = 0x25U;     // Example 8-bit address for Port B
        constexpr bval_type bval5 = (1U << 5); // 8-bit bit mask for bit 5 (0x20)

        // Inline function to write to an 8-bit register (using port_type and bval_type)
        inline void set_bit(port_type &port, bval_type bitmask)
        {
            port |= bitmask; // Set specified bit
        }

        inline void clear_bit(port_type &port, bval_type bitmask)
        {
            port &= ~bitmask; // Clear specified bit
        }

    } // namespace reg
} // namespace mcal

#endif // MCAL_REG_H
