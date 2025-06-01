#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <thread>
#include <mutex>
#include <chrono>
#include <random>
#include <atomic>
#include <map>
#include <algorithm>

// ========== Observer Pattern ==========

class IObserver
{
public:
    virtual void update(const std::string &sensorName, double value) = 0;
    virtual ~IObserver() = default;
};

// ========== Dashboard ==========

class Dashboard : public IObserver
{
    std::mutex display_mutex;

public:
    void update(const std::string &sensorName, double value) override
    {
        std::lock_guard<std::mutex> lock(display_mutex);
        std::cout << "[Dashboard] " << sensorName << ": " << value << std::endl;
    }
};

class ISubject
{
public:
    virtual void attach(std::shared_ptr<IObserver> observer) = 0;
    virtual void detach(std::shared_ptr<IObserver> observer) = 0;
    virtual void notify(double value) = 0;
    virtual ~ISubject() = default;
};

// ========== Strategy Pattern ==========

class ISensorStrategy
{
public:
    virtual double generate() = 0;
    virtual ~ISensorStrategy() = default;
};

class RandomStrategy : public ISensorStrategy
{
    std::mt19937 rng{std::random_device{}()};
    std::uniform_real_distribution<double> dist{20.0, 100.0};

public:
    double generate() override
    {
        return dist(rng);
    }
};

class SineWaveStrategy : public ISensorStrategy
{
    double time = 0.0;

public:
    double generate() override
    {
        time += 0.1;
        return 50.0 + 25.0 * std::sin(time);
    }
};

// ========== Sensor ==========

/**
 * @brief 
            Why use std::enable_shared_from_this<T>?
                It solves a common problem: getting a shared_ptr to this from inside a class that is already managed by a shared_ptr.

                public std::enable_shared_from_this<Sensor>

                allows you to call:
                
                shared_from_this()

 * 
 */
class Sensor : public ISubject, public std::enable_shared_from_this<Sensor>
{
    std::string name;
    std::vector<std::shared_ptr<IObserver>> observers;
    std::mutex mutex;
    std::unique_ptr<ISensorStrategy> strategy;
    std::thread worker;
    std::atomic<bool> running{false};

public:
    Sensor(const std::string &name, 
            std::unique_ptr<ISensorStrategy> strat)
        : name(name), 
          strategy(std::move(strat)) 
        {

        }

    void attach(std::shared_ptr<IObserver> observer) override
    {
        std::lock_guard<std::mutex> lock(mutex);
        observers.push_back(observer);
    }

    void detach(std::shared_ptr<IObserver> observer) override
    {
        std::lock_guard<std::mutex> lock(mutex);
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify(double value) override
    {
        std::lock_guard<std::mutex> lock(mutex);

        for (auto &obs : observers)
        {
            obs->update(name, value);
        }
    }

    void start()
    {
        running = true;

        worker = std::thread([this]()
                             {
            while (running) {
                double val = strategy->generate();
                notify(val);
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            } });
    }

    void stop()
    {
        running = false;
        
        if (worker.joinable())
            worker.join();
    }

    const std::string &getName() const { return name; }

    ~Sensor()
    {
        stop();
    }
};

// ========== Factory ==========

std::shared_ptr<Sensor> createSensor(const std::string &type, const std::string &name)
{
    if (type == "random")
    {
        return std::make_shared<Sensor>(name, std::make_unique<RandomStrategy>());
    }
    else if (type == "sine")
    {
        return std::make_shared<Sensor>(name, std::make_unique<SineWaveStrategy>());
    }
    else
    {
        throw std::runtime_error("Unknown sensor type: " + type);
    }
}

// ========== Main ==========

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::cout << "Sensor Monitoring Dashboard Running...\n";
    std::cout << "Press Enter to stop.\n";

    auto dashboard = std::make_shared<Dashboard>();

    std::vector<std::shared_ptr<Sensor>> sensors;

    // Create sensors
    sensors.push_back(createSensor("random", "TemperatureSensor"));
    sensors.push_back(createSensor("sine", "PressureSensor"));

    for (auto &sensor : sensors)
    {
        sensor->attach(dashboard);
        sensor->start();
    }

    std::cin.get();

    for (auto &sensor : sensors)
    {
        sensor->stop();
    }

    std::cout << "Shutting down dashboard.\n";

    return 0;
}
