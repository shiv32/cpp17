#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <memory>
#include <string>
#include <atomic>
#include <ctime>

enum class CalibrationStatus
{
    Valid,
    ExpiringSoon,
    Expired
};

class ISensor
{
public:
    virtual ~ISensor() = default;
    virtual float read() const = 0;
    virtual const std::string &getName() const = 0;
    virtual CalibrationStatus getCalibrationStatus() const = 0;
};

// Define days duration manually (C++17 compatible)
using Days = std::chrono::duration<int, std::ratio<86400>>;

// Convert YYYY-MM-DD to time_point
std::chrono::system_clock::time_point fromDate(int year, int month, int day)
{
    std::tm tm = {};
    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
    std::time_t tt = std::mktime(&tm);
    return std::chrono::system_clock::from_time_t(tt);
}

class TemperatureSensor : public ISensor
{
    std::string name_;
    std::chrono::system_clock::time_point calibrationDate_;
    Days validity_;
    Days warningBeforeExpiry_;

public:
    TemperatureSensor(const std::string &name,
                      std::chrono::system_clock::time_point calibrationDate,
                      int validityDays,
                      int warningDays = 3)
        : name_(name),
          calibrationDate_(calibrationDate),
          validity_(Days(validityDays)),
          warningBeforeExpiry_(Days(warningDays)) {}

    float read() const override
    {
        return 25.0f;
    }

    const std::string &getName() const override
    {
        return name_;
    }

    CalibrationStatus getCalibrationStatus() const override
    {
        auto now = std::chrono::system_clock::now();
        auto expiry = calibrationDate_ + validity_;
        auto warningTime = expiry - warningBeforeExpiry_;

        if (now >= expiry)
            return CalibrationStatus::Expired;
        if (now >= warningTime)
            return CalibrationStatus::ExpiringSoon;
        return CalibrationStatus::Valid;
    }
};

struct SensorStatusTracker
{
    std::shared_ptr<ISensor> sensor;
    CalibrationStatus lastStatus = CalibrationStatus::Valid;

    void updateStatus()
    {
        CalibrationStatus current = sensor->getCalibrationStatus();
        if (current != lastStatus)
        {
            lastStatus = current;
            printStatus(current);
        }
    }

    void printStatus(CalibrationStatus status) const
    {
        const std::string &name = sensor->getName();
        switch (status)
        {
        case CalibrationStatus::Valid:
            std::cout << "✅ [" << name << "] Calibration is valid.\n";
            break;
        case CalibrationStatus::ExpiringSoon:
            std::cout << "⚠️ [" << name << "] Calibration will expire soon!\n";
            break;
        case CalibrationStatus::Expired:
            std::cout << "❌ [" << name << "] Calibration expired!\n";
            break;
        }
    }
};

void monitorSensors(std::vector<SensorStatusTracker> &trackers, std::atomic<bool> &running)
{
    while (running.load())
    {
        for (auto &tracker : trackers)
        {
            tracker.updateStatus();
        }
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

int main()
{
    std::vector<std::shared_ptr<ISensor>> sensors;

    // Create sensors with calibration dates and validity
    sensors.push_back(std::make_shared<TemperatureSensor>("Sensor-1", fromDate(2025, 3, 1), 30));
    sensors.push_back(std::make_shared<TemperatureSensor>("Sensor-2", fromDate(2025, 3, 25), 10));
    sensors.push_back(std::make_shared<TemperatureSensor>("Sensor-3", fromDate(2025, 4, 1), 6));
    sensors.push_back(std::make_shared<TemperatureSensor>("Sensor-4", fromDate(2025, 4, 1), 4));

    std::vector<SensorStatusTracker> trackers;
    for (auto &s : sensors)
    {
        trackers.push_back({s});
    }

    std::atomic<bool> running{true};
    std::thread monitorThread(monitorSensors, std::ref(trackers), std::ref(running));

    std::this_thread::sleep_for(std::chrono::seconds(20));
    running = false;
    monitorThread.join();

    std::cout << "Monitoring stopped.\n";
    return 0;
}
