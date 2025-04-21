/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Template + Runtime Factory
 * @version 0.1
 * @date 2025-04-21
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include <memory>
#include <unordered_map>
#include <functional>

// ----------------- Template Logic (Strategy) -----------------
template <typename T>
class SensorHandlerImpl
{
public:
    void handle(float value)
    {
        static_cast<T *>(this)->handleImpl(value);
    }
};

// ----------------- Concrete Handlers -----------------
class TemperatureHandler : public SensorHandlerImpl<TemperatureHandler>
{
public:
    void handleImpl(float value)
    {
        std::cout << "Temp: " << value << " °C\n";
    }
};

class PressureHandler : public SensorHandlerImpl<PressureHandler>
{
public:
    void handleImpl(float value)
    {
        std::cout << "Pressure: " << value << " Pa\n";
    }
};

// ----------------- Polymorphic Wrapper -----------------
class ISensorHandler
{
public:
    virtual void handle(float value) = 0;
    virtual ~ISensorHandler() = default;
};

template <typename T>
class SensorHandlerWrapper : public ISensorHandler
{
    T impl_;

public:
    void handle(float value) override
    {
        impl_.handle(value); // Calls templated logic
    }
};

// ----------------- Runtime Factory -----------------
enum class SensorType
{
    Temperature,
    Pressure
};

class SensorFactory
{
public:
    static std::unique_ptr<ISensorHandler> create(SensorType type)
    {
        switch (type)
        {
        case SensorType::Temperature:
            return std::make_unique<SensorHandlerWrapper<TemperatureHandler>>();
        case SensorType::Pressure:
            return std::make_unique<SensorHandlerWrapper<PressureHandler>>();
        default:
            return nullptr;
        }
    }
};

// ----------------- Client Code -----------------
int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    auto handler = SensorFactory::create(SensorType::Temperature);
    if (handler)
        handler->handle(26.5f);

    auto handler2 = SensorFactory::create(SensorType::Pressure);
    if (handler2)
        handler2->handle(101325.0f);

    return 0;
}
