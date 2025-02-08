/**
 * @file main.ino
 * @author your name (you@domain.com)
 * @brief Tested SimulIDE
 * @version 0.1
 * @date 2025-02-09
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <Arduino.h> // Needed for Serial in a custom main()

int main()
{
    // Printing Pin Register Addresses
    init(); // Required to initialize Arduino core

    Serial.begin(9600);
    while (!Serial); // Wait for Serial Monitor to open

    Serial.print("Address of PORTB: ");
    Serial.println((uint16_t)&PORTB, HEX);

    Serial.print("Address of DDRB: ");
    Serial.println((uint16_t)&DDRB, HEX);

    Serial.print("Address of PINB: ");
    Serial.println((uint16_t)&PINB, HEX);

    while (1)  ; // Prevent program from exiting
   
    return 0;
}
