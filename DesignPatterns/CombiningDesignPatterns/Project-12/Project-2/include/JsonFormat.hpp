
#pragma once
#include "FormatStrategy.hpp"
#include <sstream>

class JsonFormat : public FormatStrategy {
public:
    std::string format(const std::vector<std::string>& data) override {
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

    std::string getFileExtension() const override {
        return "json";
    }
};
