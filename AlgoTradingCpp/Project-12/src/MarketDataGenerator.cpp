#include "MarketDataGenerator.h"

void MarketDataGenerator::simulateTick(Instrument& inst) {
    inst.update();
}
