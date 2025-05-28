#pragma once
#include <vector>
#include <string>

//Template method class
class Exporter
{
public:
    void exportData(const std::vector<std::string> &data);//Template method
    virtual ~Exporter() = default;

protected:
    virtual void openFile() = 0;
    virtual void writeHeader() = 0;
    virtual void writeData(const std::vector<std::string> &data) = 0;
    virtual void writeFooter() = 0;
    virtual void closeFile() = 0;
};