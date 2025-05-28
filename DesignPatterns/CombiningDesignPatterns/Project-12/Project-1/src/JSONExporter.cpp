#include "JSONExporter.hpp"

void JSONExporter::openFile()
{
    file.open("output.json");
}

void JSONExporter::writeHeader()
{
    file << "[\n";
}

void JSONExporter::writeData(const std::vector<std::string> &data)
{
    for (size_t i = 0; i < data.size(); ++i)
    {
        file << "  { \"entry\": \"" << data[i] << "\" }";
        if (i != data.size() - 1)
            file << ",";
        file << "\n";
    }
}

void JSONExporter::writeFooter()
{
    file << "]\n";
}

void JSONExporter::closeFile()
{
    file.close();
}