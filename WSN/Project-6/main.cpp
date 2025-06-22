#include <iostream>
#include <fstream>
#include <memory>
#include <sstream>
#include <vector>
#include <string>

// Interface for all sensors
class ISensor   //(Base + Strategy)
{
public:
    virtual std::string getName() const = 0;
    virtual double getValue() const = 0;
    virtual ~ISensor() = default;
};

// Example Sensor: Temperature
class TemperatureSensor : public ISensor
{
public:
    std::string getName() const override { return "Temperature"; }
    double getValue() const override { return 36.5; }
};

// Example Sensor: Humidity
class HumiditySensor : public ISensor
{
public:
    std::string getName() const override { return "Humidity"; }
    double getValue() const override { return 75.2; }
};

// Example Sensor: Pressure
class PressureSensor : public ISensor
{
public:
    std::string getName() const override { return "Pressure"; }
    double getValue() const override { return 1013.3; }
};

// Collects sensor data
class SensorManager //(Observer-style or Aggregator)
{
    std::vector<std::shared_ptr<ISensor>> sensors;

public:
    void addSensor(const std::shared_ptr<ISensor> &sensor)
    {
        sensors.push_back(sensor);
    }

    std::vector<std::pair<std::string, double>> collect() const
    {
        std::vector<std::pair<std::string, double>> result;

        for (const auto &s : sensors)
        {
            result.emplace_back(s->getName(), s->getValue());
        }
        return result;
    }
};

// Builds CSV content
class CSVBuilder    //Builder or Template Method
{
    std::ostringstream oss;

public:
    void addHeader(const std::string &col1, const std::string &col2)
    {
        oss << col1 << "," << col2 << "\n";
    }

    void addRow(const std::string &name, double value)
    {
        oss << name << "," << value << "\n";
    }

    std::string getCSV() const
    {
        return oss.str();
    }
};

// Static writer for CSV
class CSVWriter  //(Singleton or RAII wrapper)
{
public:
    static void writeToFile(const std::string &filename, const std::string &content)
    {
        std::ofstream file(filename);
        
        if (file.is_open())
        {
            file << content;
            file.close();
        }
    }
};

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Setup sensors
    SensorManager manager;
    manager.addSensor(std::make_shared<TemperatureSensor>());
    manager.addSensor(std::make_shared<HumiditySensor>());
    manager.addSensor(std::make_shared<PressureSensor>());

    // Collect data
    auto data = manager.collect();

    // Build CSV
    CSVBuilder builder;
    builder.addHeader("Sensor", "Value");

    for (const auto &[name, value] : data)
    {
        builder.addRow(name, value);
    }

    // Write to file
    CSVWriter::writeToFile("sensor_data.csv", builder.getCSV());

    std::cout << "CSV written successfully.\n";
    
    return 0;
}
