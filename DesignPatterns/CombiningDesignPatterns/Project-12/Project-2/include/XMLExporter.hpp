
#pragma once
#include "FormatStrategy.hpp"

class XMLExporter : public FormatStrategy {
public:
    std::string format(const std::vector<std::string>& data) override;
    std::string getFileExtension() const override;
};
