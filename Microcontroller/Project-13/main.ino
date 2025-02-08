// #include <avr/io.h>
// #include <util/delay.h>
#include "Led.h" // Include the header file for the Led class

// Instantiate the template for Pin 13 (PB5 on PORTB)
LED<DDRB_Reg, PORTB_Reg, PB5> led;

int main()
{

    while (1)
    {
        led.blink(100); // Blink the LED every 1000 milliseconds (1 second)
    }

    return 0;
}
