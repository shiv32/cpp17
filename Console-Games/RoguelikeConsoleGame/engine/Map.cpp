#include "Map.hpp"

Map::Map(int width, int height) {
    data.resize(height);
    for (int y = 0; y < height; ++y) {
        std::string row;
        for (int x = 0; x < width; ++x) {
            row += (x == 0 || y == 0 || x == width - 1 || y == height - 1) ? '#' : '.';
        }
        data[y] = row;
    }
}

const std::vector<std::string>& Map::getData() const {
    return data;
}
