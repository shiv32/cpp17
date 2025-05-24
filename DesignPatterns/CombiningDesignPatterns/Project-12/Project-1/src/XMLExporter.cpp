#include "XMLExporter.hpp"

void XMLExporter::openFile() { file.open("output.xml"); }
void XMLExporter::writeHeader() { file << "<Entries>\n"; }
void XMLExporter::writeData(const std::vector<std::string>& data) {
    for (const auto& line : data) file << "  <Entry>" << line << "</Entry>\n";
}
void XMLExporter::writeFooter() { file << "</Entries>\n"; }
void XMLExporter::closeFile() { file.close(); }