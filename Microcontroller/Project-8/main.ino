#include "LEDBlink.h"  // Include the header file for the Led class

Led led(13);  // Create an object of the Led class with pin 13

void setup() {
  // No need to initialize the pin in setup, it's done in the class constructor
}

void loop() {
  led.blink(1000);  // Blink the LED every 1000 milliseconds (1 second)
}
