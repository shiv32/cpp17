/**
 * @file main.ino
 * @author your name (you@domain.com)
 * @brief Tested on SimulIDE
 * @version 0.1
 * @date 2025-02-08
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <avr/io.h>
#include <util/delay.h>

int main() {
    DDRB |= (1 << PB5);  // Set PB5 (Arduino Pin 13) as OUTPUT

    while (1) {
        PORTB ^= (1 << PB5);  // Toggle LED
        _delay_ms(50000);        // Wait 500ms
    }

    return 0;
}
