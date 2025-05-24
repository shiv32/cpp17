#pragma once
#include "Exporter.hpp"
#include <memory>

class ExporterFactory {
public:
    static std::unique_ptr<Exporter> createExporter(const std::string& type);
};