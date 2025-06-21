#include "hal/gpio.hpp"
#include "hal/uart.hpp"
#include <thread>
#include <chrono>

using namespace hal;

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    GPIO led("LED1", GPIOMode::OUTPUT);
    UART uart("USART1", 9600);

    for (int i = 0; i < 5; ++i)
    {
        led.write(true);
        uart.write("LED ON");

        std::this_thread::sleep_for(std::chrono::milliseconds(300));

        led.write(false);
        uart.write("LED OFF");

        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }

    uart.write("Blinking complete.");
    
    return 0;
}
