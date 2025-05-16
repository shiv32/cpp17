#pragma once
#include <vector>
#include "Instrument.h"

class DisplayManager {
public:
    void render(const std::vector<Instrument>& instruments);
};
