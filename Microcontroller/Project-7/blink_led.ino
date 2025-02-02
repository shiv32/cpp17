/**
 * @brief Arduino Led blink code using pin address
 * 
 * Tested on
 * https://www.tinkercad.com/
 * 
 */

// C++ code
//
void setup()
{
    DDRB |= (1 << PB5);  // Set pin 13 (PB5) as OUTPUT

} 

void loop()
{
    PORTB |= (1 << PB5);  // Turn LED ON
    delay(1000);           // Wait 1 second
  
    PORTB &= ~(1 << PB5);  // Turn LED OFF
    delay(1000);           // Wait 1 second
}
 