#ifndef LED_HPP
#define LED_HPP

#include <Arduino.h> // Required for Arduino types and functions

class LED {
private:
    int pin; // Pin number for the LED

public:
    // Constructor: Initialize the LED with a pin number
    explicit LED(int ledPin);

    // Method to turn the LED on
    void on();

    // Method to turn the LED off
    void off();

    // Method to toggle the LED
    void toggle();
};

#endif // LED_HPP
