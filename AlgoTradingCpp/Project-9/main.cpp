/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief  Algorithmic trading

            candlestick chart with support and resistance levels

 * @version 0.1
 * @date 2024-10-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

// Structure to store DOHLCV data
struct DOHLCV
{
    std::string date; // Date
    double open;      // Open price
    double high;      // High price
    double low;       // Low price
    double close;     // Close price
    double volume;    // Volume
};

// Function to calculate Simple Moving Average (SMA)
std::vector<double> calculateSMA(const std::vector<double> &prices, int period)
{
    std::vector<double> sma;
    double sum = 0.0;

    for (size_t i = 0; i < prices.size(); ++i)
    {
        sum += prices[i];
        if (i >= period - 1)
        {
            if (i >= period)
            {
                sum -= prices[i - period];
            }
            sma.push_back(sum / period);
        }
        else
        {
            sma.push_back(0.0); // SMA undefined for first few points
        }
    }
    return sma;
}

// Function to simulate trading signals
void swingTrade(const std::vector<DOHLCV> &data, const std::vector<double> &smaShort, const std::vector<double> &smaLong)
{
    bool holding = false; // Track if we currently hold the stock
    double buyPrice = 0.0;

    for (size_t i = 0; i < data.size(); ++i)
    {
        if (smaShort[i] == 0.0 || smaLong[i] == 0.0)
            continue; // Skip if SMA not defined

        if (!holding && smaShort[i] > smaLong[i])
        {
            // Buy signal
            std::cout << "Buy on " << data[i].date << " at price: "
                      << std::fixed << std::setprecision(2) << data[i].close << "\n";
            holding = true;
            buyPrice = data[i].close;
        }
        else if (holding && smaShort[i] < smaLong[i])
        {
            // Sell signal
            std::cout << "Sell on " << data[i].date << " at price: "
                      << std::fixed << std::setprecision(2) << data[i].close << "\n";
            std::cout << "Profit: " << data[i].close - buyPrice << "\n";
            holding = false;
        }
    }
}

// Function to parse DOHLCV data from CSV file
std::vector<DOHLCV> parseCSV(const std::string &filename)
{
    std::vector<DOHLCV> data;
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open " << filename << "\n";
        return data;
    }

    std::string line;
    // Skip the header line
    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string token;
        DOHLCV row;

        std::getline(ss, row.date, ','); // Date
        std::getline(ss, token, ',');    // Open
        row.open = std::stod(token);
        std::getline(ss, token, ','); // High
        row.high = std::stod(token);
        std::getline(ss, token, ','); // Low
        row.low = std::stod(token);
        std::getline(ss, token, ','); // Close
        row.close = std::stod(token);
        std::getline(ss, token, ','); // Volume
        row.volume = std::stod(token);

        data.push_back(row);
    }

    file.close();
    return data;
}

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Load DOHLCV data from a CSV file
    std::string filename = "market_data.csv";
    std::vector<DOHLCV> dohlcvData = parseCSV(filename);
    if (dohlcvData.empty())
    {
        return 1;
    }

    // Extract closing prices
    std::vector<double> closingPrices;
    for (const auto &row : dohlcvData)
    {
        closingPrices.push_back(row.close);
    }

    // Parameters for moving averages
    int shortPeriod = 5; // Short-term SMA period
    int longPeriod = 20; // Long-term SMA period

    // Calculate moving averages
    std::vector<double> smaShort = calculateSMA(closingPrices, shortPeriod);
    std::vector<double> smaLong = calculateSMA(closingPrices, longPeriod);

    // Simulate swing trading
    std::cout << "Swing Trading Signals:\n";
    swingTrade(dohlcvData, smaShort, smaLong);

    return 0;
}
