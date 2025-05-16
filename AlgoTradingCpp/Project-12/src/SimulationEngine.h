#pragma once
#include <vector>
#include "Instrument.h"
#include "MarketDataGenerator.h"
#include "DisplayManager.h"

class SimulationEngine {
public:
    void run();

private:
    std::vector<Instrument> instruments;
    MarketDataGenerator generator;
    DisplayManager display;
    bool running = true;
};
