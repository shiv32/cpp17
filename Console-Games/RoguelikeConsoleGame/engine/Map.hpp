#pragma once
#include <vector>
#include <string>

class Map {
public:
    Map(int width = 40, int height = 20);
    const std::vector<std::string>& getData() const;
private:
    std::vector<std::string> data;
};
