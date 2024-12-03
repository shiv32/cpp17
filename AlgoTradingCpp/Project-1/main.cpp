/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief  Algorithmic trading calculating a moving average


 * @version 0.1
 * @date 2024-10-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <numeric>

struct MarketData
{
    std::string timestamp;
    double open;
    double high;
    double low;
    double close;
    int volume;
};

std::vector<MarketData> readCSV(const std::string &filename)
{
    std::vector<MarketData> data;
    std::ifstream file(filename);

    if (!file.is_open())
    {
        throw std::runtime_error("Could not open file");
    }

    std::string line, header;
    std::getline(file, header); // Skip the header line

    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        MarketData row;
        std::string volumeStr;

        std::getline(ss, row.timestamp, ',');
        ss >> row.open;
        ss.ignore();
        ss >> row.high;
        ss.ignore();
        ss >> row.low;
        ss.ignore();
        ss >> row.close;
        ss.ignore();
        std::getline(ss, volumeStr, ',');

        row.volume = std::stoi(volumeStr);

        data.push_back(row);
    }
    file.close();
    return data;
}

std::vector<double> calculateSMA(const std::vector<double> &prices, int period)
{
    std::vector<double> sma;
    for (size_t i = 0; i <= prices.size() - period; ++i)
    {
        double sum = std::accumulate(prices.begin() + i, prices.begin() + i + period, 0.0);
        sma.push_back(sum / period);
    }
    return sma;
}

void executeStrategy(const std::vector<MarketData> &data, int smaPeriod, std::vector<std::string> &results)
{
    std::vector<double> closePrices;
    for (const auto &row : data)
    {
        closePrices.push_back(row.close);
    }

    auto sma = calculateSMA(closePrices, smaPeriod);

    for (size_t i = 0; i < sma.size(); ++i)
    {
        std::string signal = (closePrices[i + smaPeriod - 1] > sma[i]) ? "Buy" : "Sell";
        std::string timestamp = data[i + smaPeriod - 1].timestamp;

        // Format the result as "Signal,Timestamp"
        results.push_back(signal + "," + timestamp);

        if (closePrices[i + smaPeriod - 1] > sma[i])
        {
            std::cout << "Buy signal at: " << data[i + smaPeriod - 1].timestamp << std::endl;
        }
        else
        {
            std::cout << "Sell signal at: " << data[i + smaPeriod - 1].timestamp << std::endl;
        }
    }
}

void writeCSV(const std::string &filename, const std::vector<std::string> &results)
{
    std::ofstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Could not open file to write");
    }

    // Write the header
    file << "Signal,Timestamp\n";

    // Write each row from results
    for (const auto &row : results)
    {
        file << row << "\n";
    }

    file.close();
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    try
    {
        std::string inputFile = "market_data.csv";
        std::string outputFile = "trade_signals.csv";

        // Read data
        auto data = readCSV(inputFile);

        // Execute strategy
        int smaPeriod = 5;
        // executeStrategy(data, smaPeriod);

        std::vector<std::string> results;
        executeStrategy(data, smaPeriod, results);

        // Log results (if required)
        writeCSV(outputFile, results); // Customize with your result logging logic
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
