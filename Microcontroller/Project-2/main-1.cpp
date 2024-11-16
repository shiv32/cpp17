/*
    Controlling an LED with a Class

    How to Use
    Open the Arduino IDE.
    Paste the code into a new sketch.
    Connect your Arduino to your computer.
    Select the correct board and port in the Arduino IDE.
    Upload the code to your Arduino.
*/


// Include necessary libraries
#include <Arduino.h>

// Define an LED class
class LED {
private:
    int pin; // The pin number the LED is connected to

public:
    // Constructor: Initialize the LED with the given pin
    LED(int ledPin) : pin(ledPin) {
        pinMode(pin, OUTPUT); // Set the pin as OUTPUT
    }

    // Method to turn the LED on
    void on() {
        digitalWrite(pin, HIGH);
    }

    // Method to turn the LED off
    void off() {
        digitalWrite(pin, LOW);
    }

    // Method to toggle the LED
    void toggle() {
        static bool state = false;
        state = !state;
        digitalWrite(pin, state ? HIGH : LOW);
    }
};

// Create an LED object for pin 13 (built-in LED)
LED led(13);

void setup() {
    // No need to initialize the LED pin here, as it's done in the LED constructor
}

void loop() {
    led.on();          // Turn LED on
    delay(1000);       // Wait for 1 second
    led.off();         // Turn LED off
    delay(1000);       // Wait for 1 second
}
