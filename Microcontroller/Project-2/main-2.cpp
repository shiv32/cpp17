/*

    Advanced Example: Multiple LEDs

    Why Use C++ with Arduino?
    Encapsulation: Keeps code modular and reusable.
    Scalability: Makes it easier to manage complex projects.
    Object-Oriented: Classes and objects make the code cleaner and easier to debug.

*/

#include <Arduino.h>

class LED {
private:
    int pin;

public:
    LED(int ledPin) : pin(ledPin) {
        pinMode(pin, OUTPUT);
    }

    void on() { digitalWrite(pin, HIGH); }
    void off() { digitalWrite(pin, LOW); }
    void toggle() {
        static bool state = false;
        state = !state;
        digitalWrite(pin, state ? HIGH : LOW);
    }
};

// Create LED objects for pins 8, 9, and 10
LED led1(8);
LED led2(9);
LED led3(10);

void setup() {
    // Initialization is handled in the LED constructor
}

void loop() {
    led1.on();
    led2.off();
    led3.toggle();

    delay(500); // Wait 500 ms
}
