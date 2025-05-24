#pragma once
#include "Exporter.hpp"
#include <fstream>

class CSVExporter : public Exporter {
protected:
    void openFile() override;
    void writeHeader() override;
    void writeData(const std::vector<std::string>& data) override;
    void writeFooter() override;
    void closeFile() override;

private:
    std::ofstream file;
};