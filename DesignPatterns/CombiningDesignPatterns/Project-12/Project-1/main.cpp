#include <fstream>
#include "ExporterFactory.hpp"
#include "Logger.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    Logger::getInstance().log("Application started");

    std::vector<std::string> data{"Alice,30", "Bob,25", "Carol,27"};

    //----------- Read data from text file --------------------------------------
    // std::vector<std::string> data;

    // std::ifstream infile("../data/sample.txt");

    // if (!infile.is_open())
    // {
    //     std::cerr << "Error: Could not open data/sample.txt\n";
    //     return 1;
    // }

    // std::string line;

    // while (std::getline(infile, line))
    // {
    //     data.push_back(line);
    // }
    //-------------------------------------------------------------------------------

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
