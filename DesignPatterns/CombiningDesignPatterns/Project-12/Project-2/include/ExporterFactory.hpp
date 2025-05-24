
#pragma once
#include <memory>
#include "Exporter.hpp"

class ExporterFactory {
public:
    static std::unique_ptr<Exporter> createExporter(const std::string& format);
};
