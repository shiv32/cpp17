class LED {
  private:
    volatile uint8_t *ddr;   // Pointer to DDR register
    volatile uint8_t *port;  // Pointer to PORT register
    uint8_t pin;             // Pin bit position

  public:
    // Constructor: Takes DDR, PORT, and bit position
    LED(volatile uint8_t *ddrReg, volatile uint8_t *portReg, uint8_t pinBit) {
        ddr = ddrReg;
        port = portReg;
        pin = pinBit;
        
        *ddr |= (1 << pin);  // Set pin as OUTPUT
    }

    // Turn LED ON
    void on() {
        *port |= (1 << pin);
    }

    // Turn LED OFF
    void off() {
        *port &= ~(1 << pin);
    }

    // Blink LED with a delay
    void blink(int delayTime) {
        on();
        delay(delayTime);
        off();
        delay(delayTime);
    }
};

// Create LED object for Pin 13 (PB5)
LED led(&DDRB, &PORTB, PB5);

void setup() {
    // LED object is already initialized in the constructor
}

void loop() {
    led.blink(500);  // Blink with 500ms delay
}
