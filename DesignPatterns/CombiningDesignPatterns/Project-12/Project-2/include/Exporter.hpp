
#pragma once
#include "FormatStrategy.hpp"
#include <memory>
#include <vector>
#include <string>

class Exporter {
public:
    Exporter(std::unique_ptr<FormatStrategy> strategy);
    virtual ~Exporter();

    void exportData(const std::vector<std::string>& data);

private:
    std::unique_ptr<FormatStrategy> strategy_;
};
