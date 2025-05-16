#include "Instrument.h"
#include <chrono>

Instrument::Instrument(const std::string& sym)
    : symbol(sym), price(100.0), volume(1000.0), open(100.0), high(100.0), low(100.0), close(100.0),
      rng(static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count())),
      priceDist(-1.0, 1.0), volumeDist(0.0, 50.0) {}

void Instrument::update() {
    double change = priceDist(rng);
    price += change;
    if (price < 1.0) price = 1.0;

    if (price > high) high = price;
    if (price < low) low = price;

    close = price;
    volume = volumeDist(rng) + 950.0;
}

std::string Instrument::getSymbol() const { return symbol; }
double Instrument::getPrice() const { return price; }
double Instrument::getVolume() const { return volume; }
double Instrument::getOpen() const { return open; }
double Instrument::getHigh() const { return high; }
double Instrument::getLow() const { return low; }
double Instrument::getClose() const { return close; }
