#pragma once
#include <iostream>

enum class PinState
{
    LOW,
    HIGH
};

class GPIO
{
public:
    void write(int pin, PinState state)
    {
        std::cout << "[MOCK GPIO] Pin " << pin << " set to "
                  << (state == PinState::HIGH ? "HIGH" : "LOW") << "\n";
    }
    PinState read(int pin)
    {
        std::cout << "[MOCK GPIO] Reading pin " << pin << "\n";
        return PinState::HIGH;
    }
};
