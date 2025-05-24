#include "Exporter.hpp"

void Exporter::exportData(const std::vector<std::string>& data) {
    openFile();
    writeHeader();
    writeData(data);
    writeFooter();
    closeFile();
}