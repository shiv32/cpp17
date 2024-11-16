#include "src/LED.hpp" // Include the LED header file

// Create an LED object for the built-in LED on pin 13
LED led(13);

void setup() {
    // No additional setup required as the LED class handles it
}

void loop() {
    led.toggle(); // Toggle the LED
    delay(500);   // Wait for 500 milliseconds
}
