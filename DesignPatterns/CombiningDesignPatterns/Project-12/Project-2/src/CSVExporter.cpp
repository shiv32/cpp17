
#include "CSVExporter.hpp"
#include <sstream>

std::string CSVExporter::format(const std::vector<std::string>& data) {
    std::ostringstream oss;
    for (const auto& line : data) {
        oss << line << "\n";
    }
    return oss.str();
}

std::string CSVExporter::getFileExtension() const {
    return "csv";
}
