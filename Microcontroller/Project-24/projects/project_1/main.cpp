#include "hal/gpio.hpp"
#include <thread>
#include <chrono>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    hal::GPIO led("LED1", hal::GPIOMode::OUTPUT);
    
    for (int i = 0; i < 5; ++i)
    {
        led.write(true);
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        led.write(false);
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    
    return 0;
}
