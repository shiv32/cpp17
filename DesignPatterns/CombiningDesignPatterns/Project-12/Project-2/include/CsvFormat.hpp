
#pragma once
#include "FormatStrategy.hpp"
#include <sstream>

class CsvFormat : public FormatStrategy {
public:
    std::string format(const std::vector<std::string>& data) override {
        std::ostringstream oss;
        for (const auto& line : data) {
            oss << line << "\n";
        }
        return oss.str();
    }

    std::string getFileExtension() const override {
        return "csv";
    }
};
