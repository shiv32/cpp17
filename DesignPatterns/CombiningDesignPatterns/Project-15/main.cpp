// Sensor Monitoring System (Console App)
// C++17 Implementation with Multiple Design Patterns

#include <iostream>
#include <vector>
#include <memory>
#include <map>
#include <functional>
#include <string>
#include <chrono>
#include <thread>
#include <random>

// -------------------------- Observer Pattern -----------------------------
class ISensorObserver
{
public:
    virtual void onSensorUpdate(const std::string &name, double value) = 0;
    virtual ~ISensorObserver() = default;
};

// -------------------------- Strategy Pattern -----------------------------
class IDataProcessingStrategy
{
public:
    virtual double process(double value) = 0;
    virtual ~IDataProcessingStrategy() = default;
};

class RawDataStrategy : public IDataProcessingStrategy
{
public:
    double process(double value) override { return value; }
};

class SmoothingStrategy : public IDataProcessingStrategy
{
public:
    double process(double value) override
    {
        static double previous = value;
        double smoothed = (value + previous) / 2.0;
        previous = smoothed;
        return smoothed;
    }
};

// -------------------------- Sensor Base Class -----------------------------
class Sensor
{
protected:
    std::string name;
    double value = 0.0;
    std::vector<ISensorObserver *> observers;
    std::unique_ptr<IDataProcessingStrategy> strategy;

public:
    Sensor(std::string n, std::unique_ptr<IDataProcessingStrategy> s)
        : name(std::move(n)), strategy(std::move(s)) {}

    const std::string &getName() const { return name; }
    const double &getValue() const { return value; }

    virtual void read() = 0;

    void attach(ISensorObserver *obs) { observers.push_back(obs); }

    void notify()
    {
        double processed = strategy->process(value);
        for (auto *obs : observers)
        {
            obs->onSensorUpdate(name, processed);
        }
    }

    virtual ~Sensor() = default;
};

// -------------------------- Concrete Sensors -----------------------------
class TemperatureSensor : public Sensor
{
public:
    TemperatureSensor(const std::string &n, std::unique_ptr<IDataProcessingStrategy> s)
        : Sensor(n, std::move(s)) {}
    void read() override
    {
        value = 20 + rand() % 10; // Simulate temp
        notify();
    }
};

class HumiditySensor : public Sensor
{
public:
    HumiditySensor(const std::string &n, std::unique_ptr<IDataProcessingStrategy> s)
        : Sensor(n, std::move(s)) {}
    void read() override
    {
        value = 50 + rand() % 20; // Simulate humidity
        notify();
    }
};

class MotionSensor : public Sensor
{
public:
    MotionSensor(const std::string &n, std::unique_ptr<IDataProcessingStrategy> s)
        : Sensor(n, std::move(s)) {}
    void read() override
    {
        value = rand() % 2; // Simulate motion detected (0 or 1)
        notify();
    }
};

// -------------------------- Factory Method -----------------------------
class SensorFactory
{
public:
    static std::unique_ptr<Sensor> createSensor(const std::string &type, const std::string &name)
    {
        std::unique_ptr<IDataProcessingStrategy> strategy;

        if (type == "temperature")
        {
            strategy = std::make_unique<SmoothingStrategy>();
            return std::make_unique<TemperatureSensor>(name, std::move(strategy));
        }
        else if (type == "humidity")
        {
            strategy = std::make_unique<RawDataStrategy>();
            return std::make_unique<HumiditySensor>(name, std::move(strategy));
        }
        else if (type == "motion")
        {
            strategy = std::make_unique<RawDataStrategy>();
            return std::make_unique<MotionSensor>(name, std::move(strategy));
        }
        return nullptr;
    }
};

// -------------------------- Decorator Pattern -----------------------------
class SensorDecorator : public Sensor
{
protected:
    std::unique_ptr<Sensor> wrappedSensor;

public:
    SensorDecorator(std::unique_ptr<Sensor> s)
        : Sensor(s->getName(), nullptr), wrappedSensor(std::move(s)) {}

    void read() override
    {
        wrappedSensor->read();
    }
};

class ThresholdAlertDecorator : public SensorDecorator
{
    double threshold;

public:
    ThresholdAlertDecorator(std::unique_ptr<Sensor> s, double t)
        : SensorDecorator(std::move(s)), threshold(t) {}

    void read() override
    {
        wrappedSensor->read();
        if (wrappedSensor->getValue() > threshold)
        {
            std::cout << "[ALERT] " << wrappedSensor->getName() << " crossed threshold!\n";
        }
    }
};

// -------------------------- Singleton Pattern -----------------------------
class SensorManager
{
private:
    std::vector<std::unique_ptr<Sensor>> sensors;
    static SensorManager *instance;

    SensorManager() = default;

public:
    static SensorManager *getInstance()
    {
        if (!instance)
            instance = new SensorManager();
        return instance;
    }

    void addSensor(std::unique_ptr<Sensor> sensor)
    {
        sensors.push_back(std::move(sensor));
    }

    void pollSensors()
    {
        for (auto &sensor : sensors)
        {
            sensor->read();
        }
    }
};

SensorManager *SensorManager::instance = nullptr;

// -------------------------- Observer Implementation -----------------------------
class ConsoleLogger : public ISensorObserver
{
public:
    void onSensorUpdate(const std::string &name, double value) override
    {
        std::cout << "[LOG] " << name << " = " << value << "\n";
    }
};

// -------------------------- Command Pattern -----------------------------
class ISensorCommand
{
public:
    virtual void execute(SensorManager *manager) = 0;
    virtual ~ISensorCommand() = default;
};

class PollCommand : public ISensorCommand
{
public:
    void execute(SensorManager *manager) override
    {
        manager->pollSensors();
    }
};

// -------------------------- Main -----------------------------
int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    auto logger = std::make_unique<ConsoleLogger>();
    auto manager = SensorManager::getInstance();

    auto tempSensor = SensorFactory::createSensor("temperature", "TempSensor1");
    tempSensor->attach(logger.get());

    auto humiditySensor = SensorFactory::createSensor("humidity", "HumiditySensor1");
    humiditySensor->attach(logger.get());

    auto motionSensor = SensorFactory::createSensor("motion", "MotionSensor1");
    motionSensor->attach(logger.get());

    auto thresholdSensor = std::make_unique<ThresholdAlertDecorator>(
        SensorFactory::createSensor("temperature", "TempSensor1"), 25.0);
    thresholdSensor->attach(logger.get());

    manager->addSensor(std::move(tempSensor));
    manager->addSensor(std::move(humiditySensor));
    manager->addSensor(std::move(motionSensor));
    manager->addSensor(std::move(thresholdSensor));

    PollCommand poll;

    for (int i = 0; i < 5; ++i)
    {
        poll.execute(manager);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
