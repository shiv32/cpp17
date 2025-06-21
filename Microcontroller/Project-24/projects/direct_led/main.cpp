#include "app/led.hpp"
#include <thread>
#include <chrono>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    
    // Simulated registers
    static std::uint8_t port_value = 0x00;
    static std::uint8_t port_dir = 0x00;

    // LED on bit 0 of port
    led led0(reinterpret_cast<std::uintptr_t>(&port_value), 0x01);

    for (int i = 0; i < 5; ++i)
    {
        led0.toggle();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}
