#include <cstdint>
#include <iostream>

// Simulated memory array for testing
std::uint8_t simulated_memory[256] = {0};

class led
{
public:
    // Convenient typedefs for port and bit mask types
    typedef std::uint8_t port_type;
    typedef std::uint8_t bval_type;

private:
    port_type port_address; // Hardware address of the port
    bval_type bit_mask;     // Bitmask for the specific pin

public:
    // Constructor to initialize the LED with port and bit mask
    constexpr led(port_type port, bval_type bit)
        : port_address(port), bit_mask(bit) {}

    // Method to turn the LED on
    void on() const
    {
        *reinterpret_cast<volatile bval_type *>(&simulated_memory[port_address]) |= bit_mask;
    }

    // Method to turn the LED off
    void off() const
    {
        *reinterpret_cast<volatile bval_type *>(&simulated_memory[port_address]) &= ~bit_mask;
    }

    // Method to toggle the LED state
    void toggle() const
    {
        *reinterpret_cast<volatile bval_type *>(&simulated_memory[port_address]) ^= bit_mask;
    }

    // Print the current state of the port for debugging
    void print_state() const
    {
        std::cout << "Port 0x" << std::hex << static_cast<int>(port_address)
                  << " state: 0x" << static_cast<int>(simulated_memory[port_address]) << std::endl;
    }
};

// Simulated hardware register namespace
namespace mcal
{
    namespace reg
    {
        constexpr led::port_type portb = 0x25U;     // Simulated address for Port B
        constexpr led::bval_type bval5 = (1U << 5); // Bit mask for bit 5
    } // namespace reg
} // namespace mcal

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Initialize Port B to 0
    simulated_memory[mcal::reg::portb] = 0x00;

    // Create an LED object
    const led led_b5{mcal::reg::portb, mcal::reg::bval5};

    // Turn the LED on
    led_b5.on();
    led_b5.print_state();

    // Turn the LED off
    led_b5.off();
    led_b5.print_state();

    // Toggle the LED
    led_b5.toggle();
    led_b5.print_state();

    return 0;
}
