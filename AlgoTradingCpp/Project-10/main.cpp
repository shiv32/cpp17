/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief  Algorithmic trading
                Calculates a Volume Moving Average (VMA)
            
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

// Function to identify volume spikes
void analyzeVolume(const std::vector<DOHLCV> &data, const std::vector<double> &volumeSMA, double threshold)
{
    std::cout << "\nVolume Analysis:\n";
    for (size_t i = 0; i < data.size(); ++i)
    {
        if (volumeSMA[i] > 0.0 && data[i].volume > threshold * volumeSMA[i])
        {
            std::cout << "Volume Spike on " << data[i].date
                      << " | Volume: " << data[i].volume
                      << " | SMA: " << std::fixed << std::setprecision(2) << volumeSMA[i] << "\n";
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

    // Extract volume data
    std::vector<double> volumes;
    for (const auto &row : dohlcvData)
    {
        volumes.push_back(row.volume);
    }

    // Parameters for Volume Moving Average
    int vmaPeriod = 10;                // Volume SMA period
    double volumeSpikeThreshold = 2.0; // Threshold for volume spike (2x VMA)

    // Calculate Volume Moving Average
    std::vector<double> volumeSMA = calculateSMA(volumes, vmaPeriod);

    // Perform volume analysis
    analyzeVolume(dohlcvData, volumeSMA, volumeSpikeThreshold);

    return 0;
}
