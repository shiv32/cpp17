#include "ExporterFactory.hpp"
#include "Logger.hpp"
#include <fstream>

int main()
{
    Logger::getInstance().log("Application started");

    std::vector<std::string> data;
    std::ifstream infile("../data/sample.txt");
    if (!infile.is_open())
    {
        std::cerr << "Error: Could not open data/sample.txt\n";
        return 1;
    }

    std::string line;
    while (std::getline(infile, line))
    {
        data.push_back(line);
    }

    std::cout << "Loaded " << data.size() << " entries from sample.txt\n";

    std::string format;
    std::cout << "Enter export format (csv/json/xml): ";
    std::cin >> format;

    auto exporter = ExporterFactory::createExporter(format);
    if (exporter)
    {
        exporter->exportData(data);
    }
    else
    {
        std::cout << "Unsupported format!\n";
    }

    Logger::getInstance().log("Application ended");
    return 0;
}
