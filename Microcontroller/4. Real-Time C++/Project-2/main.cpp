#include <iostream>
#include <cstdint>

#define TRACE std::clog << __PRETTY_FUNCTION__ << std::endl;

// Simulated memory array for testing
// The size of the array is specified as 256,
// meaning it can hold 256 individual 8-bit unsigned integers (or bytes).
// Simulated memory buffer with 256 bytes, initialized to 0
std::uint8_t simulated_memory[256] = {0};

namespace mcal
{
    namespace reg
    {
        // Define port types and bit mask types explicitly as 8-bit
        using port_type = std::uint8_t;
        using bval_type = std::uint8_t;

        // Example: Define addresses or constants for 8-bit registers
        constexpr port_type port2 = 0x25U;     // Example 8-bit address for Port B
        constexpr bval_type bval0 = (1U << 5); // 8-bit bit mask for bit 5 (0x20)
        constexpr bval_type bval1 = (1U << 6); // 8-bit bit mask for bit 6 (0x40)

    } // namespace reg
} // namespace mcal

class led_base
{
public:
    virtual void toggle() = 0; // Pure abstract.
    virtual ~led_base() {}     // Virtual destructor.
    // Interface for querying the LED state.
    bool state_is_on() const { return is_on; }

protected:
    bool is_on;
    // A protected default constructor.
    led_base() : is_on(false) {}

private:
    // Private non-implemented copy constructor.
    led_base(const led_base &) = delete;

    // Private non-implemented copy assignment operator.
    const led_base &operator=(const led_base &) = delete;
};

class led_port : public led_base
{
public:
    typedef std::uint8_t port_type;
    typedef std::uint8_t bval_type;

    led_port(const port_type p, const bval_type b) : port(p), bval(b)
    {
    }

    virtual ~led_port() {}

    virtual void toggle()
    {
        // Toggle the LED.
        //*reinterpret_cast<volatile bval_type *>(port) ^= bval;
        *reinterpret_cast<volatile bval_type *>(&simulated_memory[port]) ^= ~bval;

        // Toggle the is_on indication flag.
        is_on = !is_on;

        TRACE
    }

private:
    const port_type port;
    const bval_type bval;
};

class pwm
{
public:
    explicit pwm(const int channel) : duty_cycle(0U) {}
    ~pwm() {}

    void set_duty(const std::uint8_t duty)
    {
        // Limit the duty cycle to 0...100.
        duty_cycle = std::min<std::uint8_t>(duty, 100U);

        // Set the duty cycle in the PWM hardware.
    }

    std::uint8_t get_duty() const
    {
        return duty_cycle;
    }

private:
    std::uint8_t duty_cycle;
};

class led_pwm : public led_base
{
public:
    explicit led_pwm(pwm *p) : my_pwm(p) {}
    virtual ~led_pwm() {}

    virtual void toggle()
    {
        // Toggle the LED with the PWM signal.
        is_on = (my_pwm->get_duty() > 0U);

        my_pwm->set_duty(is_on ? 0U : 100U);

        is_on = !is_on;

        TRACE
    }

    // This LED class also supports dimming.
    void dimming(const std::uint8_t duty)
    {
        my_pwm->set_duty(duty);
        is_on = (duty != 0U);
    }

private:
    pwm *my_pwm;
};

namespace
{
    // Two LEDs on port2.0 and port2.1
    led_port led0{mcal::reg::port2, mcal::reg::bval0};
    led_port led1{mcal::reg::port2, mcal::reg::bval1};

    pwm pwm0{0};
    pwm pwm1{1};

    // Two LEDs connected to pwm0 and pwm1.
    led_pwm led2{&pwm0};
    led_pwm led3{&pwm1};
}

void do_something()
{
    // Toggle L0-L3.
    led0.toggle();
    led1.toggle();
    led2.toggle();
    led3.toggle();
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    do_something();

    return 0;
}
