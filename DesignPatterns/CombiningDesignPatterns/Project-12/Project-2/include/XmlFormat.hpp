
#pragma once
#include "FormatStrategy.hpp"
#include <sstream>

class XmlFormat : public FormatStrategy {
public:
    std::string format(const std::vector<std::string>& data) override {
        std::ostringstream oss;
        oss << "<Data>\n";
        for (const auto& line : data) {
            oss << "  <Entry>" << line << "</Entry>\n";
        }
        oss << "</Data>";
        return oss.str();
    }

    std::string getFileExtension() const override {
        return "xml";
    }
};
