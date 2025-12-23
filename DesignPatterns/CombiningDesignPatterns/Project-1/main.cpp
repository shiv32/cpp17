/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Factory + Strategy in C++
 * @version 0.1
 * @date 2025-04-21
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include <memory>

// -------------------- Strategy Interface --------------------
class SensorHandler
{
public:
    virtual void handle(float value) = 0;
    virtual ~SensorHandler() = default;
};

// -------------------- Concrete Strategies --------------------
class TemperatureSensorHandler : public SensorHandler
{
public:
    void handle(float value) override
    {
        std::cout << "Handling temperature: " << value << " °C\n";
    }
};

class PressureSensorHandler : public SensorHandler
{
public:
    void handle(float value) override
    {
        std::cout << "Handling pressure: " << value << " Pa\n";
    }
};

class HumiditySensorHandler : public SensorHandler
{
public:
    void handle(float value) override
    {
        std::cout << "Handling humidity: " << value << " %\n";
    }
};

// -------------------- Factory --------------------
enum class SensorType
{
    Temperature,
    Pressure,
    Humidity,
    Unknown
};

class SensorHandlerFactory
{
public:
    static std::unique_ptr<SensorHandler> create(SensorType type)
    {
        switch (type)
        {
        case SensorType::Temperature:
            return std::make_unique<TemperatureSensorHandler>();
        case SensorType::Pressure:
            return std::make_unique<PressureSensorHandler>();
        case SensorType::Humidity:
            return std::make_unique<HumiditySensorHandler>();
        default:
            return nullptr;
        }
    }
};

// -------------------- Client Code --------------------
int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Simulated sensor values
    float sensorValue = 101.5;

    SensorType type = SensorType::Pressure;
    // SensorType type = SensorType::Humidity;
    // SensorType type = SensorType::Temperature;
    // SensorType type = SensorType::Unknown;

    auto handler = SensorHandlerFactory::create(type);

    if (handler)
    {
        handler->handle(sensorValue); // Strategy in action
    }
    else
    {
        std::cout << "Unknown sensor type !\n";
    }

    return 0;
}
