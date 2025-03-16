#include <stdint.h>

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