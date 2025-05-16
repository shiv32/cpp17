#pragma once
#include <string>
#include <random>

class Instrument {
public:
    Instrument(const std::string& symbol);
    void update();
    std::string getSymbol() const;
    double getPrice() const;
    double getVolume() const;
    double getOpen() const;
    double getHigh() const;
    double getLow() const;
    double getClose() const;

private:
    std::string symbol;
    double price;
    double volume;
    double open;
    double high;
    double low;
    double close;

    std::mt19937 rng;
    std::uniform_real_distribution<> priceDist;
    std::uniform_real_distribution<> volumeDist;
};
