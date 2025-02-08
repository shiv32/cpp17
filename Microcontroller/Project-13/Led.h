#ifndef LED_H
#define LED_H

// #include <Arduino.h>
// #include <util/delay.h>

template <typename DDR, typename PORT, uint8_t BIT>
class LED
{
public:
    // Setup the pin as OUTPUT
    static void begin()
    {
        DDR::reg |= (1 << BIT); // Set pin as OUTPUT
    }

    // Turn the LED ON
    static void on()
    {
        PORT::reg |= (1 << BIT);
    }

    // Turn the LED OFF
    static void off()
    {
        PORT::reg &= ~(1 << BIT);
    }

    // Blink the LED with a given delay time
    static void blink(int delayTime)
    {
        on();
        _delay_ms(delayTime);
        off();
        _delay_ms(delayTime);
    }
};

// Define register access structures
struct DDRB_Reg
{
    static volatile uint8_t &reg;
};
struct PORTB_Reg
{
    static volatile uint8_t &reg;
};

// Assign actual register addresses
volatile uint8_t &DDRB_Reg::reg = DDRB;
volatile uint8_t &PORTB_Reg::reg = PORTB;

#endif
