/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief  Algorithmic trading

    Generate a mock dataset for a stock with columns: Date, OPEN, HIGH, LOW, CLOSE, and VOLUME.
    This program uses random values to simulate daily price changes and volumes, writes the data into a CSV file,
    and ensures a logical relationship between the generated values.

 * @version 0.1
 * @date 2024-10-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <fstream>
#include <random>
#include <iomanip>
#include <vector>
#include <string>

// Function to generate random stock prices and volumes
void generateMockData(const std::string &filename, const std::string &startDate, int numDays,
                      double startPrice, double volatility, int minVolume, int maxVolume)
{
    // Open file for writing
    std::ofstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    // Write header
    file << "Date,OPEN,HIGH,LOW,CLOSE,VOLUME\n";

    // Random number generators
    std::random_device rd;
    std::mt19937 generator(rd());
    std::normal_distribution<double> priceChangeDist(0, volatility);     // Price change
    std::uniform_int_distribution<int> volumeDist(minVolume, maxVolume); // Volume range

    // Date variables
    int year, month, day;
    sscanf(startDate.c_str(), "%d-%d-%d", &year, &month, &day);

    // Initial price
    double prevClose = startPrice;

    for (int i = 0; i < numDays; ++i)
    {
        // Generate OPEN price (based on previous CLOSE)
        double open = prevClose + priceChangeDist(generator);
        open = std::max(1.0, open); // Ensure positive price

        // Generate HIGH and LOW prices
        double high = open + std::abs(priceChangeDist(generator));
        double low = open - std::abs(priceChangeDist(generator));
        low = std::max(1.0, low); // Ensure positive price

        // Generate CLOSE price
        double close = low + (high - low) * ((double)rand() / RAND_MAX);

        // Generate VOLUME
        int volume = volumeDist(generator);

        // Format date
        char date[11];
        sprintf(date, "%04d-%02d-%02d", year, month, day);

        // Write to file
        file << date << ","
             << std::fixed << std::setprecision(2) << open << ","
             << high << ","
             << low << ","
             << close << ","
             << volume << "\n";

        // Update previous CLOSE
        prevClose = close;

        // Increment date (simple logic, assumes 30 days per month)
        ++day;
        if (day > 30)
        {
            day = 1;
            ++month;
            if (month > 12)
            {
                month = 1;
                ++year;
            }
        }
    }

    file.close();
    std::cout << "Mock dataset written to " << filename << std::endl;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Parameters for the dataset
    const std::string filename = "market_data.csv";
    const std::string startDate = "2023-01-01";
    const int numDays = 365;
    const double startPrice = 100.0;
    const double volatility = 2.0; // Standard deviation of daily price changes
    const int minVolume = 1000;
    const int maxVolume = 100000;

    // Generate mock data
    generateMockData(filename, startDate, numDays, startPrice, volatility, minVolume, maxVolume);

    return 0;
}
