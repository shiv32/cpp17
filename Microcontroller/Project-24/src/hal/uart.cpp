#include "hal/uart.hpp"
#include <iostream>

using namespace hal;

UART::UART(const std::string& name, int baudrate)
    : uart_name(name), baud(baudrate) {}

void UART::write(const std::string& msg) {
    std::cout << "[UART " << uart_name << " @ " << baud << "bps] " << msg << std::endl;
}

std::string UART::getName() const {
    return uart_name;
}
