#include "hal/gpio.hpp"
#include <iostream>

using namespace hal;

GPIO::GPIO(const std::string &name, GPIOMode mode)
    : pin_name(name), mode(mode), state(false) {}

void GPIO::write(bool value)
{
    if (mode == GPIOMode::OUTPUT)
    {
        state = value;
        std::cout << "[GPIO " << pin_name << "] -> " << (value ? "HIGH" : "LOW") << "\n";
    }
}

bool GPIO::read() const
{
    return state;
}
