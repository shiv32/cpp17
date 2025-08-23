#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <map>

// Data structure to hold sensor measurements
struct SensorData
{
    double temperature;
    double pressure;
    std::string timestamp;
    // Add other sensor data fields
};

// Abstract Strategy for report generation
class IReportStrategy
{
public:
    virtual ~IReportStrategy() = default;
    virtual void generateReport(const std::vector<SensorData> &data, const std::string &filename) = 0;
};

// Concrete Strategy for PDF reports
class PDFReportStrategy : public IReportStrategy
{
public:
    void generateReport(const std::vector<SensorData> &data, const std::string &filename) override
    {
        // Implement PDF generation logic
        // You can use libraries like libharu or wkhtmltopdf
    }
};

// Concrete Strategy for CSV reports
class CSVReportStrategy : public IReportStrategy
{
public:
    void generateReport(const std::vector<SensorData> &data, const std::string &filename) override
    {
        // Implement CSV generation logic
    }
};

// Factory for creating report strategies
class ReportStrategyFactory
{
public:
    static std::unique_ptr<IReportStrategy> createStrategy(const std::string &format)
    {
        if (format == "pdf")
        {
            return std::make_unique<PDFReportStrategy>();
        }
        else if (format == "csv")
        {
            return std::make_unique<CSVReportStrategy>();
        }
        throw std::runtime_error("Unsupported report format");
    }
};

// Context class that uses the strategy
class ReportGenerator
{
private:
    std::unique_ptr<IReportStrategy> strategy;

public:
    void setStrategy(const std::string &format)
    {
        strategy = ReportStrategyFactory::createStrategy(format);
    }

    void generateReport(const std::vector<SensorData> &data, const std::string &filename)
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
    // Sample sensor data
    std::vector<SensorData> sensorData = {
        {25.5, 1013.2, "2025-08-23 10:00:00"},
        {26.0, 1013.1, "2025-08-23 10:01:00"}};

    try
    {
        ReportGenerator generator;

        // Generate PDF report
        generator.setStrategy("pdf");
        generator.generateReport(sensorData, "sensor_report.pdf");

        // Generate CSV report
        generator.setStrategy("csv");
        generator.generateReport(sensorData, "sensor_report.csv");
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}