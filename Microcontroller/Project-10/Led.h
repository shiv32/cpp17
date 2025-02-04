#ifndef LED_H
#define LED_H

#include <Arduino.h>

template <typename DDR, typename PORT, uint8_t BIT>
class Led {
  public:
    // Constructor to initialize the LED pin
    Led();

    // Method to turn the LED on
    void turnOn();

    // Method to turn the LED off
    void turnOff();

    // Method to blink the LED with a delay
    void blink(int delayTime);
};

// Define register access structures
struct DDRB_Reg { static volatile uint8_t &reg; };
struct PORTB_Reg { static volatile uint8_t &reg; };

// Assign actual register addresses
volatile uint8_t &DDRB_Reg::reg = DDRB;
volatile uint8_t &PORTB_Reg::reg = PORTB;

// Constructor to initialize the LED pin
template <typename DDR, typename PORT, uint8_t BIT>
Led<DDR, PORT, BIT>::Led() {
  // Set the pin as output by setting the corresponding bit in the DDR register
  DDR::reg |= (1 << BIT);  // Set pin as OUTPUT
};

// Method to turn the LED on
template <typename DDR, typename PORT, uint8_t BIT>
void Led<DDR, PORT, BIT>::turnOn() {
 PORT::reg |= (1 << BIT);
}

// Method to turn the LED off
template <typename DDR, typename PORT, uint8_t BIT>
void Led<DDR, PORT, BIT>::turnOff() {
 PORT::reg &= ~(1 << BIT);
}

// Method to blink the LED with a delay
template <typename DDR, typename PORT, uint8_t BIT>
void Led<DDR, PORT, BIT>::blink(int delayTime) {
  turnOn();
  delay(delayTime);  // Wait for the specified time
  turnOff();
  delay(delayTime);  // Wait for the specified time
}
#endif
