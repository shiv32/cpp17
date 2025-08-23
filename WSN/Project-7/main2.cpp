#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <fstream>

// Base struct for all sensor data types
struct BaseSensorData
{
    std::string timestamp;
    std::string sensorId;

    BaseSensorData(const std::string &ts, const std::string &id)
        : timestamp(ts), sensorId(id) {}
    virtual ~BaseSensorData() = default;
};

// Measurement data structure
struct MeasurementData : public BaseSensorData
{
    double temperature;
    double pressure;
    double humidity;

    MeasurementData(const std::string &ts, const std::string &id,
                    double temp, double press, double hum)
        : BaseSensorData(ts, id), temperature(temp),
          pressure(press), humidity(hum) {}
};

// Calibration data structure
struct CalibrationData : public BaseSensorData
{
    double offsetTemp;
    double offsetPressure;
    double gainFactor;
    std::string calibrationMethod;

    CalibrationData(const std::string &ts, const std::string &id,
                    double offTemp, double offPress, double gain,
                    const std::string &method)
        : BaseSensorData(ts, id), offsetTemp(offTemp),
          offsetPressure(offPress), gainFactor(gain),
          calibrationMethod(method) {}
};

// Template Strategy interface
template <typename T>
class IReportStrategy
{
public:
    virtual ~IReportStrategy() = default;
    virtual void generateReport(const std::vector<T> &data,
                                const std::string &filename) = 0;
};

// Specialized PDF Strategy for Measurement Data
class PDFMeasurementStrategy : public IReportStrategy<MeasurementData>
{
public:
    void generateReport(const std::vector<MeasurementData> &data,
                        const std::string &filename) override
    {
        // Implement PDF generation for measurement data
        std::cout << "Generating PDF measurement report: " << filename << std::endl;
    }
};

// Specialized PDF Strategy for Calibration Data
class PDFCalibrationStrategy : public IReportStrategy<CalibrationData>
{
public:
    void generateReport(const std::vector<CalibrationData> &data,
                        const std::string &filename) override
    {
        // Implement PDF generation for calibration data
        std::cout << "Generating PDF calibration report: " << filename << std::endl;
    }
};

// Specialized CSV Strategy for Measurement Data
class CSVMeasurementStrategy : public IReportStrategy<MeasurementData>
{
public:
    void generateReport(const std::vector<MeasurementData> &data,
                        const std::string &filename) override
    {
        std::ofstream file(filename);
        if (!file)
        {
            throw std::runtime_error("Could not open file: " + filename);
        }

        // Write CSV header
        file << "Timestamp,SensorID,Temperature,Pressure,Humidity\n";

        // Write data rows
        for (const auto &measurement : data)
        {
            file << measurement.timestamp << ","
                 << measurement.sensorId << ","
                 << measurement.temperature << ","
                 << measurement.pressure << ","
                 << measurement.humidity << "\n";
        }

        std::cout << "Generating PDF measurement report: " << filename << std::endl;
    }
};

// Specialized CSV Strategy for Calibration Data
class CSVCalibrationStrategy : public IReportStrategy<CalibrationData>
{
public:
    void generateReport(const std::vector<CalibrationData> &data,
                        const std::string &filename) override
    {
        std::ofstream file(filename);
        if (!file)
        {
            throw std::runtime_error("Could not open file: " + filename);
        }

        // Write CSV header
        file << "Timestamp,SensorID,OffsetTemp,OffsetPressure,GainFactor,CalibrationMethod\n";

        // Write data rows
        for (const auto &calibration : data)
        {
            file << calibration.timestamp << ","
                 << calibration.sensorId << ","
                 << calibration.offsetTemp << ","
                 << calibration.offsetPressure << ","
                 << calibration.gainFactor << ","
                 << calibration.calibrationMethod << "\n";
        }

        std::cout << "Generating CSV calibration report: " << filename << std::endl;
    }
};

// Template Report Generator
template <typename T>
class ReportGenerator
{
private:
    std::unique_ptr<IReportStrategy<T>> strategy;

public:
    void setStrategy(std::unique_ptr<IReportStrategy<T>> newStrategy)
    {
        strategy = std::move(newStrategy);
    }

    void generateReport(const std::vector<T> &data, const std::string &filename)
    {
        if (!strategy)
        {
            throw std::runtime_error("Report strategy not set");
        }
        
        strategy->generateReport(data, filename);
    }
};

int main()
{
    try
    {
        // Create measurement data
        std::vector<MeasurementData> measurementData = {
            MeasurementData("2025-08-23 10:00:00", "SENSOR001", 25.5, 1013.2, 45.0),
            MeasurementData("2025-08-23 10:01:00", "SENSOR001", 26.0, 1013.1, 44.8)};

        // Create calibration data
        std::vector<CalibrationData> calibrationData = {
            CalibrationData("2025-08-23 09:00:00", "SENSOR001", 0.5, 2.0, 1.02, "TWO_POINT"),
            CalibrationData("2025-08-23 09:30:00", "SENSOR001", 0.6, 1.8, 1.03, "THREE_POINT")};

        ReportGenerator<MeasurementData> measurementReporter;
        ReportGenerator<CalibrationData> calibrationReporter;

        // Generate PDF reports
        measurementReporter.setStrategy(std::make_unique<PDFMeasurementStrategy>());
        measurementReporter.generateReport(measurementData, "measurement_report.pdf");

        calibrationReporter.setStrategy(std::make_unique<PDFCalibrationStrategy>());
        calibrationReporter.generateReport(calibrationData, "calibration_report.pdf");

        // Generate CSV reports
        measurementReporter.setStrategy(std::make_unique<CSVMeasurementStrategy>());
        measurementReporter.generateReport(measurementData, "measurement_report.csv");

        calibrationReporter.setStrategy(std::make_unique<CSVCalibrationStrategy>());
        calibrationReporter.generateReport(calibrationData, "calibration_report.csv");
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}