/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * 
 * Tested on simulIDE
 * 
 * avr-g++ -mmcu=atmega328p -Os -o main.elf main.cpp && avr-objcopy -O ihex main.elf main.hex
 * 
 * 
 * 
 * @version 0.1
 * @date 2025-03-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#define F_CPU 16000000UL  // Set clock frequency (e.g., 16MHz for Arduino Uno)

#include <avr/io.h>
#include <util/delay.h>

// Define a simple LED class
class LED {
public:
    LED(uint8_t pin) { 
        DDRB |= (1 << pin); // Set pin as output
        _pin = pin;
    }

    void on() { PORTB |= (1 << _pin); }  // Turn LED ON
    void off() { PORTB &= ~(1 << _pin); } // Turn LED OFF

private:
    uint8_t _pin;  // Store pin number
};

int main() {
    LED led(5); // Create an LED object on pin PB5

    while (true) {
        led.on();
         _delay_ms(500);
        led.off();
         _delay_ms(500);
    }
}
