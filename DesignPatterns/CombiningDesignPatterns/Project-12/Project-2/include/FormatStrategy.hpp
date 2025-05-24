
#pragma once
#include <string>
#include <vector>

class FormatStrategy {
public:
    virtual ~FormatStrategy() = default;
    virtual std::string format(const std::vector<std::string>& data) = 0;
    virtual std::string getFileExtension() const = 0;
};
