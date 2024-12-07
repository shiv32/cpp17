/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief  Algorithmic trading
                Bollinger Band Swing Trading Logic

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
#include <cmath>

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
std::vector<double> calculateSMA(const std::vector<double> &data, int period)
{
    std::vector<double> sma;
    double sum = 0.0;

    for (size_t i = 0; i < data.size(); ++i)
    {
        sum += data[i];
        if (i >= period - 1)
        {
            if (i >= period)
            {
                sum -= data[i - period];
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

// Function to calculate Standard Deviation
std::vector<double> calculateStdDev(const std::vector<double> &data, const std::vector<double> &sma, int period)
{
    std::vector<double> stddev(data.size(), 0.0);

    for (size_t i = period - 1; i < data.size(); ++i)
    {
        double sumSq = 0.0;
        for (size_t j = i - period + 1; j <= i; ++j)
        {
            sumSq += std::pow(data[j] - sma[i], 2);
        }
        stddev[i] = std::sqrt(sumSq / period);
    }
    return stddev;
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

// Bollinger Band Swing Trading
void bollingerBandSwingTrade(const std::vector<DOHLCV> &data, int period, double multiplier)
{
    std::vector<double> closingPrices;
    for (const auto &row : data)
    {
        closingPrices.push_back(row.close);
    }

    // Calculate SMA and Standard Deviation
    std::vector<double> sma = calculateSMA(closingPrices, period);
    std::vector<double> stddev = calculateStdDev(closingPrices, sma, period);

    // Track trades
    bool holding = false;
    double buyPrice = 0.0;
    double totalProfit = 0.0;

    std::cout << "Bollinger Band Swing Trading Signals:\n";

    for (size_t i = 0; i < data.size(); ++i)
    {
        if (i < period - 1)
            continue; // Skip until enough data points

        double upperBand = sma[i] + multiplier * stddev[i];
        double lowerBand = sma[i] - multiplier * stddev[i];

        if (!holding && closingPrices[i] < lowerBand)
        {
            // Buy signal
            std::cout << "Buy on " << data[i].date << " at price: "
                      << std::fixed << std::setprecision(2) << closingPrices[i] << "\n";
            holding = true;
            buyPrice = closingPrices[i];
        }
        else if (holding && closingPrices[i] > upperBand)
        {
            // Sell signal
            std::cout << "Sell on " << data[i].date << " at price: "
                      << std::fixed << std::setprecision(2) << closingPrices[i] << "\n";
            double profit = closingPrices[i] - buyPrice;
            totalProfit += profit;
            std::cout << "Profit: " << profit << "\n";
            holding = false;
        }
    }

    std::cout << "Total Profit: " << totalProfit << "\n";
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

    // Bollinger Band Parameters
    int period = 20;       // Lookback period for SMA and StdDev
    double multiplier = 2; // Bollinger Band width multiplier

    // Perform Bollinger Band Swing Trading
    bollingerBandSwingTrade(dohlcvData, period, multiplier);

    return 0;
}
