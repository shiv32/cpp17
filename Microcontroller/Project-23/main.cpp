#include "logic/app_logic.hpp"
#include "stm32_hal_mock/gpio.hpp"
#include "stm32_hal_mock/uart.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    GPIO gpio;
    UART uart;
    
    AppLogic app(gpio, uart);
    app.run();

    return 0;
}
