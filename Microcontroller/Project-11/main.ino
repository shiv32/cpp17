void setup() {
    Serial.begin(9600);
    Serial.print("C++ compiler: ");
    Serial.println(__cplusplus); // Print the C++ standard version
}

void loop() {}