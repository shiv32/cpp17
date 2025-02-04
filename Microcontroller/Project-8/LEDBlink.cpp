#include "LEDBlink.h"

// Constructor to initialize the LED pin
Led::Led(int pinNumber) {
  pin = pinNumber;
  pinMode(pin, OUTPUT);  // Set the pin as an output
}

// Method to turn the LED on
void Led::turnOn() {
  digitalWrite(pin, HIGH);  // Set pin high (LED on)
}

// Method to turn the LED off
void Led::turnOff() {
  digitalWrite(pin, LOW);   // Set pin low (LED off)
}

// Method to blink the LED with a delay
void Led::blink(int delayTime) {
  turnOn();
  delay(delayTime);  // Wait for the specified time
  turnOff();
  delay(delayTime);  // Wait for the specified time
}
