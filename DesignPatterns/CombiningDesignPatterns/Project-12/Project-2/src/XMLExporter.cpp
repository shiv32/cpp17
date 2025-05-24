
#include "XMLExporter.hpp"
#include <sstream>

std::string XMLExporter::format(const std::vector<std::string>& data) {
    std::ostringstream oss;
    oss << "<Data>\n";
    for (const auto& line : data) {
        oss << "  <Entry>" << line << "</Entry>\n";
    }
    oss << "</Data>";
    return oss.str();
}

std::string XMLExporter::getFileExtension() const {
    return "xml";
}
