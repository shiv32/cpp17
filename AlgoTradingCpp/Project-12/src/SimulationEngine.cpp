#include "SimulationEngine.h"
#include <thread>
#include <chrono>

void SimulationEngine::run() {
    instruments = {
        Instrument("AAPL"),
        Instrument("GOOG"),
        Instrument("MSFT")
    };

    while (running) {
        for (auto& inst : instruments) {
            generator.simulateTick(inst);
        }
        display.render(instruments);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}
