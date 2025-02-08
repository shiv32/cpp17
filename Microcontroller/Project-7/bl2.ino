//Tested on SimulIDE

//------------------------------------(0)---------------------------------
void setup() {
    pinMode(13, OUTPUT);
}
void loop() {
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    delay(500);
}


//---------------------------------(1)----------------------------------
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
//----------------------------------(2)----------------------------------------------
template<uint8_t PIN>
class LED {
public:
    // Setup the pin as OUTPUT
    static void begin() {
        pinMode(PIN, OUTPUT);
    }

    // Turn the LED ON
    static void on() {
        digitalWrite(PIN, HIGH);
    }

    // Turn the LED OFF
    static void off() {
        digitalWrite(PIN, LOW);
    }

    // Blink the LED with a given delay time
    static void blink(int delayTime) {
        on();
        delay(delayTime);
        off();
        delay(delayTime);
    }
};

// Instantiate the template for pin 13
LED<13> led;

void setup() {
    led.begin();
}

void loop() {
    led.blink(500);  // Blink every 500ms
}
//-------------------------------(3)--------------------------------------
template<typename DDR, typename PORT, uint8_t BIT>
class LED {
public:
    // Setup the pin as OUTPUT
    static void begin() {
        DDR::reg |= (1 << BIT);  // Set pin as OUTPUT
    }

    // Turn the LED ON
    static void on() {
        PORT::reg |= (1 << BIT);
    }

    // Turn the LED OFF
    static void off() {
        PORT::reg &= ~(1 << BIT);
    }

    // Blink the LED with a given delay time
    static void blink(int delayTime) {
        on();
        delay(delayTime);
        off();
        delay(delayTime);
    }
};

// Define register access structures
struct DDRB_Reg { static volatile uint8_t &reg; };
struct PORTB_Reg { static volatile uint8_t &reg; };

// Assign actual register addresses
volatile uint8_t &DDRB_Reg::reg = DDRB;
volatile uint8_t &PORTB_Reg::reg = PORTB;

// Instantiate the template for Pin 13 (PB5 on PORTB)
LED<DDRB_Reg, PORTB_Reg, PB5> led;

void setup() {
    led.begin();
}

void loop() {
    led.blink(100);  // Blink every 500ms
}
