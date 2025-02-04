#include "Led.h"

// Instantiate the template for Pin 13 (PB5 on PORTB)
Led<DDRB_Reg, PORTB_Reg, PB5> led;


void setup() {
  // No need to initialize the pin in setup, it's done in the class constructor
}

void loop() {
  led.blink(1000);  // Blink the LED every 1000 milliseconds (1 second)
}
