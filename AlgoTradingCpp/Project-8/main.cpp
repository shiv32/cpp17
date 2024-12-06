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
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

// Define a structure for candlestick data
struct Candle {
    std::string date;
    double open;
    double high;
    double low;
    double close;
};

// Function to read CSV file and load candlestick data
std::vector<Candle> readCandlestickData(const std::string& filename) {
    std::vector<Candle> data;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return data;
    }

    std::string line;
    std::getline(file, line); // Skip header
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        Candle candle;
        std::string value;

        std::getline(ss, candle.date, ',');
        std::getline(ss, value, ','); candle.open = std::stod(value);
        std::getline(ss, value, ','); candle.high = std::stod(value);
        std::getline(ss, value, ','); candle.low = std::stod(value);
        std::getline(ss, value, ','); candle.close = std::stod(value);

        data.push_back(candle);
    }
    file.close();
    return data;
}

// Function to calculate support and resistance levels
void calculateSupportResistance(const std::vector<Candle>& data, std::vector<double>& supportLevels, std::vector<double>& resistanceLevels, int window = 5) {
    for (size_t i = window; i < data.size() - window; ++i) {
        // Check for local maxima (Resistance)
        bool isResistance = true;
        for (int j = -window; j <= window; ++j) {
            if (data[i].high < data[i + j].high) {
                isResistance = false;
                break;
            }
        }
        if (isResistance) {
            resistanceLevels.push_back(data[i].high);
        }

        // Check for local minima (Support)
        bool isSupport = true;
        for (int j = -window; j <= window; ++j) {
            if (data[i].low > data[i + j].low) {
                isSupport = false;
                break;
            }
        }
        if (isSupport) {
            supportLevels.push_back(data[i].low);
        }
    }

    // Deduplicate and simplify levels
    std::sort(supportLevels.begin(), supportLevels.end());
    supportLevels.erase(std::unique(supportLevels.begin(), supportLevels.end()), supportLevels.end());

    std::sort(resistanceLevels.begin(), resistanceLevels.end());
    resistanceLevels.erase(std::unique(resistanceLevels.begin(), resistanceLevels.end()), resistanceLevels.end());
}

void generateGnuplotFiles(const std::string& dataFilename, const std::string& scriptFilename, const std::vector<Candle>& data, const std::vector<double>& supportLevels, const std::vector<double>& resistanceLevels) {
    // Output data file for GNUPlot
    std::ofstream dataFile(dataFilename);
    if (!dataFile.is_open()) {
        std::cerr << "Error: Could not open file " << dataFilename << std::endl;
        return;
    }

    // Write data in <Index> <Open> <High> <Low> <Close> format
    for (size_t i = 0; i < data.size(); ++i) {
        dataFile << i + 1 << " " 
                 << data[i].open << " " 
                 << data[i].high << " " 
                 << data[i].low << " " 
                 << data[i].close << "\n";
    }
    dataFile.close();

    // Generate GNUPlot script
    std::ofstream scriptFile(scriptFilename);
    if (!scriptFile.is_open()) {
        std::cerr << "Error: Could not open file " << scriptFilename << std::endl;
        return;
    }

    scriptFile << "set title 'Candlestick Chart with Support and Resistance'\n";
    scriptFile << "set xlabel 'Candles'\n";
    scriptFile << "set ylabel 'Price'\n";
    scriptFile << "set grid\n";
    scriptFile << "set term qt size 1200,800\n";
    scriptFile << "set style line 1 lc rgb 'blue' lt 2 lw 2\n";
    scriptFile << "set style line 2 lc rgb 'orange' lt 2 lw 2\n";

    // Plot support and resistance lines
    for (const auto& level : supportLevels) {
        scriptFile << "set arrow from 0," << level << " to " << data.size() << "," << level << " nohead ls 1\n";
    }
    for (const auto& level : resistanceLevels) {
        scriptFile << "set arrow from 0," << level << " to " << data.size() << "," << level << " nohead ls 2\n";
    }

    // Plot candlestick chart
    scriptFile << "plot '" << dataFilename << "' using 1:2:3:4:5 with candlesticks title 'Candlesticks' whiskerbars lc rgb 'black'\n";

    scriptFile.close();
    std::cout << "Generated GNUPlot data: " << dataFilename << "\n";
    std::cout << "Generated GNUPlot script: " << scriptFilename << "\n";
}

int main() {
    std::string inputFile = "market_data.csv"; // Input CSV file
    std::string dataFile = "candlestick_data.dat"; // GNUPlot data file
    std::string scriptFile = "candlestick_plot.plt"; // GNUPlot script file

    // Step 1: Read candlestick data
    std::vector<Candle> data = readCandlestickData(inputFile);
    if (data.empty()) {
        std::cerr << "Error: No data loaded from the input file." << std::endl;
        return 1;
    }

    // Step 2: Calculate support and resistance levels
    std::vector<double> supportLevels, resistanceLevels;
    calculateSupportResistance(data, supportLevels, resistanceLevels, 5);

    // Step 3: Generate GNUPlot files
    generateGnuplotFiles(dataFile, scriptFile, data, supportLevels, resistanceLevels);

    // Step 4: Run GNUPlot
    std::string command = "gnuplot -persist " + scriptFile;
    system(command.c_str());

    return 0;
}








//-------------------------------------------------------------
// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <vector>
// #include <string>
// #include <algorithm>

// // Define a structure for candlestick data
// struct Candle {
//     std::string date;
//     double open;
//     double high;
//     double low;
//     double close;
// };

// // Function to read CSV file and load candlestick data
// std::vector<Candle> readCandlestickData(const std::string& filename) {
//     std::vector<Candle> data;
//     std::ifstream file(filename);
//     if (!file.is_open()) {
//         std::cerr << "Error: Could not open file " << filename << std::endl;
//         return data;
//     }

//     std::string line;
//     std::getline(file, line); // Skip header
//     while (std::getline(file, line)) {
//         std::stringstream ss(line);
//         Candle candle;
//         std::string value;

//         std::getline(ss, candle.date, ',');
//         std::getline(ss, value, ','); candle.open = std::stod(value);
//         std::getline(ss, value, ','); candle.high = std::stod(value);
//         std::getline(ss, value, ','); candle.low = std::stod(value);
//         std::getline(ss, value, ','); candle.close = std::stod(value);

//         data.push_back(candle);
//     }
//     file.close();
//     return data;
// }

// // Function to calculate support and resistance levels
// void calculateSupportResistance(const std::vector<Candle>& data, std::vector<double>& supportLevels, std::vector<double>& resistanceLevels, int window = 5) {
//     for (size_t i = window; i < data.size() - window; ++i) {
//         // Check for local maxima (Resistance)
//         bool isResistance = true;
//         for (int j = -window; j <= window; ++j) {
//             if (data[i].high < data[i + j].high) {
//                 isResistance = false;
//                 break;
//             }
//         }
//         if (isResistance) {
//             resistanceLevels.push_back(data[i].high);
//         }

//         // Check for local minima (Support)
//         bool isSupport = true;
//         for (int j = -window; j <= window; ++j) {
//             if (data[i].low > data[i + j].low) {
//                 isSupport = false;
//                 break;
//             }
//         }
//         if (isSupport) {
//             supportLevels.push_back(data[i].low);
//         }
//     }
// }

// // Function to generate GNUPlot data and script
// void generateGnuplotFiles(const std::string& dataFilename, const std::string& scriptFilename, const std::vector<Candle>& data, const std::vector<double>& supportLevels, const std::vector<double>& resistanceLevels) {
//     // Output data file for GNUPlot
//     std::ofstream dataFile(dataFilename);
//     if (!dataFile.is_open()) {
//         std::cerr << "Error: Could not open file " << dataFilename << std::endl;
//         return;
//     }

//     for (size_t i = 0; i < data.size(); ++i) {
//         dataFile << i + 1 << " " << data[i].open << " " << data[i].high << " " << data[i].low << " " << data[i].close << "\n";
//     }
//     dataFile.close();

//     // Generate GNUPlot script
//     std::ofstream scriptFile(scriptFilename);
//     if (!scriptFile.is_open()) {
//         std::cerr << "Error: Could not open file " << scriptFilename << std::endl;
//         return;
//     }

//     scriptFile << "set title 'Candlestick Chart with Support and Resistance'\n";
//     scriptFile << "set xlabel 'Candles'\n";
//     scriptFile << "set ylabel 'Price'\n";
//     scriptFile << "set grid\n";
//     scriptFile << "set style line 1 lc rgb 'blue' lt 1 lw 2\n";
//     scriptFile << "set style line 2 lc rgb 'red' lt 1 lw 2\n";

//     // Draw support and resistance lines
//     for (const auto& level : supportLevels) {
//         scriptFile << "set arrow from 0," << level << " to " << data.size() << "," << level << " nohead ls 1\n";
//     }
//     for (const auto& level : resistanceLevels) {
//         scriptFile << "set arrow from 0," << level << " to " << data.size() << "," << level << " nohead ls 2\n";
//     }

//     // Plot the candlestick chart
//     scriptFile << "plot '" << dataFilename << "' using 1:3:4:2:5 with candlesticks title 'Candlestick' lt -1\n";
//     scriptFile.close();

//     std::cout << "Generated GNUPlot data: " << dataFilename << "\n";
//     std::cout << "Generated GNUPlot script: " << scriptFilename << "\n";
// }

// int main() {
//     std::string inputFile = "market_data.csv"; // Input CSV file
//     std::string dataFile = "candlestick_data.dat"; // GNUPlot data file
//     std::string scriptFile = "candlestick_plot.plt"; // GNUPlot script file

//     // Step 1: Read candlestick data
//     std::vector<Candle> data = readCandlestickData(inputFile);
//     if (data.empty()) {
//         std::cerr << "Error: No data loaded from the input file." << std::endl;
//         return 1;
//     }

//     // Step 2: Calculate support and resistance levels
//     std::vector<double> supportLevels, resistanceLevels;
//     calculateSupportResistance(data, supportLevels, resistanceLevels, 5);

//     // Step 3: Generate GNUPlot files
//     generateGnuplotFiles(dataFile, scriptFile, data, supportLevels, resistanceLevels);

//     // Step 4: Run GNUPlot
//     std::string command = "gnuplot -persist " + scriptFile;
//     system(command.c_str());

//     return 0;
// }
