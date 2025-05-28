
#include "ExporterFactory.hpp"
#include "Logger.hpp"
#include <fstream>
#include <unistd.h>
#include <limits.h>
#include <vector>
#include <iostream>

std::string getExecutablePath()
{
    char result[PATH_MAX];
    ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
    std::string path;
    if (count != -1)
    {
        path = std::string(result, count);
        auto pos = path.find_last_of("/");
        if (pos != std::string::npos)
        {
            path = path.substr(0, pos);
        }
    }
    return path;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    Logger::getInstance().log("Application started");

    std::vector<std::string> data;
    std::string rootPath = getExecutablePath();
    std::string filePath = rootPath + "/../data/sample.txt";

    std::ifstream infile(filePath);
    if (!infile.is_open())
    {
        std::cerr << "Error: Could not open " << filePath << "\n";
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
