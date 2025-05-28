#include "CSVExporter.hpp"

void CSVExporter::openFile()
{
    file.open("output.csv");
}

void CSVExporter::writeHeader()
{
    file << "Name,Age\n";
}

void CSVExporter::writeData(const std::vector<std::string> &data)
{
    for (const auto &line : data)
        file << line << "\n";
}

void CSVExporter::writeFooter()
{
}

void CSVExporter::closeFile()
{
    file.close();
}