#pragma once

#include <cstdint>
#include <string>

void uart_print(const std::string &str);

class led
{
public:
    using port_type = std::uintptr_t;
    using bval_type = std::uint8_t;

    led(const port_type p, const bval_type b);

    void toggle() const;

private:
    const port_type port;
    const bval_type bval;
};
