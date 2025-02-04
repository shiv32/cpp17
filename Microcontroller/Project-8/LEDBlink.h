#ifndef LED_H
#define LED_H

#include <Arduino.h>

class Led {
  private:
    int pin; // Pin number for the LED

  public:
    // Constructor to initialize the LED pin
    Led(int pinNumber);

    // Method to turn the LED on
    void turnOn();

    // Method to turn the LED off
    void turnOff();

    // Method to blink the LED with a delay
    void blink(int delayTime);
};

#endif
