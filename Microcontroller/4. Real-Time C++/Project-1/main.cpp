#include <iostream>
#include <cstdint>

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
        *reinterpret_cast<volatile bval_type *>(port) ^= bval;

        // Toggle the is_on indication flag.
        is_on = !is_on;
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

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    return 0;
}
