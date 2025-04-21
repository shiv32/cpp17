/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Template-Based Strategy (Compile-Time)
 * @version 0.1
 * @date 2025-04-21
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>

// ----------------- Sensor Handlers -----------------
struct TemperatureHandler
{
    void handle(float value)
    {
        std::cout << "Temperature: " << value << " °C\n";
    }
};

struct PressureHandler
{
    void handle(float value)
    {
        std::cout << "Pressure: " << value << " Pa\n";
    }
};

struct HumidityHandler
{
    void handle(float value)
    {
        std::cout << "Humidity: " << value << " %\n";
    }
};

// ----------------- Template Processor -----------------
template <typename Handler>
class SensorProcessor
{
    Handler handler_;

public:
    void process(float value)
    {
        handler_.handle(value);
    }
};

// ----------------- Usage -----------------
int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    SensorProcessor<TemperatureHandler> tempProcessor;
    tempProcessor.process(25.3);

    SensorProcessor<PressureHandler> pressureProcessor;
    pressureProcessor.process(101325);

    return 0;
}
