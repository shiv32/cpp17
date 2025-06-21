#pragma once
#include "../stm32_hal_mock/gpio.hpp"
#include "../stm32_hal_mock/uart.hpp"

class AppLogic
{
    GPIO &gpio;
    UART &uart;

public:
    AppLogic(GPIO &g, UART &u) : gpio(g), uart(u) {}

    void run()
    {
        gpio.write(13, PinState::HIGH);
        uart.send("LED ON");

        auto val = gpio.read(13);
        if (val == PinState::HIGH)
            uart.send("Confirmed: Pin HIGH");
    }
};
