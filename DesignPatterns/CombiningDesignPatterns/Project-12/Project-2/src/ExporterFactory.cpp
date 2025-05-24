
#include "ExporterFactory.hpp"
#include "CSVExporter.hpp"
#include "JSONExporter.hpp"
#include "XMLExporter.hpp"

std::unique_ptr<Exporter> ExporterFactory::createExporter(const std::string& format) {
    if (format == "csv") return std::make_unique<Exporter>(std::make_unique<CSVExporter>());
    if (format == "json") return std::make_unique<Exporter>(std::make_unique<JSONExporter>());
    if (format == "xml") return std::make_unique<Exporter>(std::make_unique<XMLExporter>());
    return nullptr;
}
