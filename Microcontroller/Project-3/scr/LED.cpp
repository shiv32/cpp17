#include "LED.hpp"

// Constructor: Initialize the LED pin
LED::LED(int ledPin) : pin(ledPin) {
    pinMode(pin, OUTPUT); // Set the pin as OUTPUT
}

// Turn the LED on
void LED::on() {
    digitalWrite(pin, HIGH);
}

// Turn the LED off
void LED::off() {
    digitalWrite(pin, LOW);
}

// Toggle the LED
void LED::toggle() {
    static bool state = false; // Static to retain value between calls
    state = !state;
    digitalWrite(pin, state ? HIGH : LOW);
}
