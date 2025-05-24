
#include "JSONExporter.hpp"
#include <sstream>

std::string JSONExporter::format(const std::vector<std::string>& data) {
    std::ostringstream oss;
    oss << "[\n";
    for (size_t i = 0; i < data.size(); ++i) {
        oss << "  \"" << data[i] << "\"";
        if (i < data.size() - 1) oss << ",";
        oss << "\n";
    }
    oss << "]";
    return oss.str();
}

std::string JSONExporter::getFileExtension() const {
    return "json";
}
