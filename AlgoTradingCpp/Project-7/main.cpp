/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief  Algorithmic trading

         C++ Code for Bollinger Bands with Backtesting.

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
#include <cmath>
#include <string>

struct StockData
{
    std::string date;
    double open, high, low, close;
    long volume;
};

std::vector<StockData> loadStockData(const std::string &filename)
{
    std::vector<StockData> data;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open())
    {
        std::cerr << "Error opening file." << std::endl;
        return data;
    }

    // Skip the header line
    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        StockData record;
        std::string volumeStr;

        std::getline(ss, record.date, ',');
        ss >> record.open;
        ss.ignore(1);
        ss >> record.high;
        ss.ignore(1);
        ss >> record.low;
        ss.ignore(1);
        ss >> record.close;
        ss.ignore(1);
        std::getline(ss, volumeStr);
        record.volume = std::stol(volumeStr);

        data.push_back(record);
    }

    file.close();
    return data;
}

std::vector<double> calculateMovingAverage(const std::vector<StockData> &data, int period)
{
    std::vector<double> movingAverage;
    double sum = 0;

    for (size_t i = 0; i < data.size(); ++i)
    {
        sum += data[i].close;

        if (i >= period)
        {
            sum -= data[i - period].close;
            movingAverage.push_back(sum / period);
        }
        else if (i == period - 1)
        {
            movingAverage.push_back(sum / period);
        }
    }

    return movingAverage;
}

void trendFollowingStrategy(const std::vector<StockData> &data, const std::vector<double> &movingAverage)
{
    for (size_t i = 1; i < data.size(); ++i)
    {
        if (data[i].close > movingAverage[i - 1] && data[i - 1].close <= movingAverage[i - 2])
        {
            std::cout << "Buy signal on " << data[i].date << " at price " << data[i].close << "\n";
        }
        else if (data[i].close < movingAverage[i - 1] && data[i - 1].close >= movingAverage[i - 2])
        {
            std::cout << "Sell signal on " << data[i].date << " at price " << data[i].close << "\n";
        }
    }
}

double backtest(const std::vector<StockData> &data, const std::vector<double> &movingAverage)
{
    double balance = 10000; // Initial balance
    double position = 0;    // Stock holdings
    double buyPrice = 0;

    for (size_t i = 1; i < data.size(); ++i)
    {
        if (data[i].close > movingAverage[i - 1] && data[i - 1].close <= movingAverage[i - 2])
        {
            // Buy signal
            position = balance / data[i].close;
            buyPrice = data[i].close;
            balance = 0;
            std::cout << "Bought on " << data[i].date << " at price " << buyPrice << "\n";
        }
        else if (data[i].close < movingAverage[i - 1] && data[i - 1].close >= movingAverage[i - 2] && position > 0)
        {
            // Sell signal
            balance = position * data[i].close;
            position = 0;
            std::cout << "Sold on " << data[i].date << " at price " << data[i].close << "\n";
        }
    }

    return balance;
}
//-----------------------------------------------
std::vector<double> loadClosePricesFromCSV(const std::string &fileName)
{
    std::vector<double> prices;
    std::ifstream file(fileName);
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open the file " << fileName << std::endl;
        return prices;
    }

    std::string line;
    bool isHeader = true; // Skip the first line if it contains headers
    while (std::getline(file, line))
    {
        if (isHeader)
        {
            isHeader = false;
            continue;
        }
        std::stringstream ss(line);
        std::string date, open, high, low, close;
        std::getline(ss, date, ',');
        std::getline(ss, open, ',');
        std::getline(ss, high, ',');
        std::getline(ss, low, ',');
        std::getline(ss, close, ',');

        try
        {
            prices.push_back(std::stod(close)); // Use "Close" price for Bollinger Bands
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Error: Invalid close price in CSV: " << close << std::endl;
        }
    }

    file.close();
    return prices;
}

// Function to calculate the Simple Moving Average (SMA)
double calculateSMA(const std::vector<double> &prices, int period, int currentIndex)
{
    if (currentIndex + 1 < period)
        return 0.0; // Not enough data
    double sum = 0.0;
    for (int i = currentIndex; i > currentIndex - period; --i)
    {
        sum += prices[i];
    }
    return sum / period;
}

// Function to calculate the Standard Deviation
double calculateStdDev(const std::vector<double> &prices, int period, int currentIndex, double sma)
{
    if (currentIndex + 1 < period)
        return 0.0; // Not enough data
    double sum = 0.0;
    for (int i = currentIndex; i > currentIndex - period; --i)
    {
        sum += pow(prices[i] - sma, 2);
    }
    return sqrt(sum / period);
}

// Function to calculate Bollinger Bands
void calculateBollingerBands(const std::vector<double> &prices, int period, double stdDevFactor,
                             std::vector<double> &upperBand, std::vector<double> &lowerBand, std::vector<double> &middleBand)
{
    for (int i = 0; i < prices.size(); ++i)
    {
        double sma = calculateSMA(prices, period, i);
        double stdDev = calculateStdDev(prices, period, i, sma);
        double upper = sma + stdDevFactor * stdDev;
        double lower = sma - stdDevFactor * stdDev;

        middleBand.push_back(sma);
        upperBand.push_back(upper);
        lowerBand.push_back(lower);
    }
}

// Backtesting function
void backtestStrategy(const std::vector<double> &prices, const std::vector<double> &upperBand,
                      const std::vector<double> &lowerBand, int period)
{
    bool inPosition = false;
    double entryPrice = 0.0;
    double profit = 0.0;

    for (size_t i = period; i < prices.size(); ++i)
    {
        if (!inPosition && prices[i] < lowerBand[i])
        {
            // Buy signal
            inPosition = true;
            entryPrice = prices[i];
            std::cout << "Buy at price: " << entryPrice << " (Index " << i + 2 << ")" << std::endl;
        }
        else if (inPosition && prices[i] > upperBand[i])
        {
            // Sell signal
            double exitPrice = prices[i];
            profit += exitPrice - entryPrice;
            inPosition = false;
            std::cout << "Sell at price: " << exitPrice << " (Index " << i + 2 << ")" << std::endl;
        }
    }

    // Print final profit
    std::cout << "Final Profit/Loss: " << profit << std::endl;
}

//--------------------------------------------
int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    const std::string filename = "market_data.csv";

    std::vector<double> prices = loadClosePricesFromCSV(filename);

    if (prices.empty())
    {
        std::cerr << "No data loaded from CSV file." << std::endl;
        return 1;
    }

    int period = 20;           // Moving average period (e.g., 20 for daily data)
    double stdDevFactor = 2.0; // Standard deviation multiplier

    std::vector<double> upperBand, lowerBand, middleBand;
    calculateBollingerBands(prices, period, stdDevFactor, upperBand, lowerBand, middleBand);

    // Backtest the strategy
    backtestStrategy(prices, upperBand, lowerBand, period);

    return 0;

    //--------------------------------------------------------------------------
    // const int movingAveragePeriod = 5;

    // // Load stock data
    // std::vector<StockData> data = loadStockData(filename);
    // if (data.empty())
    // {
    //     std::cerr << "No data loaded. Exiting.\n";
    //     return 1;
    // }

    // // Calculate the moving average
    // std::vector<double> movingAverage = calculateMovingAverage(data, movingAveragePeriod);

    // // Print buy/sell signals
    // std::cout << "Trend Following Strategy Signals:\n";
    // trendFollowingStrategy(data, movingAverage);

    // // Backtest the strategy
    // double finalBalance = backtest(data, movingAverage);
    // std::cout << "Final balance after backtesting: $" << finalBalance << "\n";

    return 0;
}