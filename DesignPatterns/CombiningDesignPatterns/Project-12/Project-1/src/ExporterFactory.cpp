#include "ExporterFactory.hpp"
#include "CSVExporter.hpp"
#include "JSONExporter.hpp"
#include "XMLExporter.hpp"

std::unique_ptr<Exporter> ExporterFactory::createExporter(const std::string& type) {
    if (type == "csv") return std::make_unique<CSVExporter>();
    if (type == "json") return std::make_unique<JSONExporter>();
    if (type == "xml") return std::make_unique<XMLExporter>();
    return nullptr;
}