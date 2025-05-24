
#include "Exporter.hpp"
#include <fstream>

Exporter::Exporter(std::unique_ptr<FormatStrategy> strategy)
    : strategy_(std::move(strategy)) {}

Exporter::~Exporter() = default;

void Exporter::exportData(const std::vector<std::string>& data) {
    std::string content = strategy_->format(data);
    std::string filename = "output." + strategy_->getFileExtension();
    std::ofstream out(filename);
    out << content;
}
