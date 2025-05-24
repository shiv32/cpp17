
#pragma once
#include "FormatStrategy.hpp"

class CSVExporter : public FormatStrategy {
public:
    std::string format(const std::vector<std::string>& data) override;
    std::string getFileExtension() const override;
};
