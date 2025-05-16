#include "DisplayManager.h"
#include <iostream>
#include <iomanip>

void DisplayManager::render(const std::vector<Instrument>& instruments) {
    system("clear"); // For Windows use "cls"
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "SYMBOL\tPRICE\tVOLUME\tOPEN\tHIGH\tLOW\tCLOSE\n";
    for (const auto& inst : instruments) {
        std::cout << inst.getSymbol() << "\t"
                  << inst.getPrice() << "\t"
                  << inst.getVolume() << "\t"
                  << inst.getOpen() << "\t"
                  << inst.getHigh() << "\t"
                  << inst.getLow() << "\t"
                  << inst.getClose() << "\n";
    }
    std::cout << "-------------------------------------------------------------\n";
}
