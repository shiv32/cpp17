/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief  Algorithmic trading

            Read market_data.csv and draw Candlestick Chart using gnuplot.

 * @version 0.1
 * @date 2024-10-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

void CandlestickChart(const std::string &dataFile)
{
    const std::string gnuplotScript = "stock_plot.gp";

    // Write gnuplot script
    std::ofstream script(gnuplotScript);
    if (!script.is_open())
    {
        std::cerr << "Error: Unable to create gnuplot script file" << std::endl;
        return;
    }

    //--------------------------------------------------------------------
    // Set up the gnuplot script
    // script << "set terminal wxt size 1600,800\n"; // Display size
    script << "set terminal qt size 1600,800\n"; // Display size
    script << "set xdata time\n";                // Treat X-axis as time

    // script << "set timefmt '%Y-%m-%d'\n"; //2023-01-01 Input date format in the CSV file
    // script << "set format x '%Y-%m-%d'\n"; // Output date format on X-axis

    script << "set timefmt '%d-%b-%Y'\n";  // 04-Dec-2024 Input date format in the CSV file
    script << "set format x '%d-%b-%Y'\n"; // Output date format on X-axis

    script << "set grid\n";                      // Enable grid
    script << "set title 'Candlestick Chart'\n"; // Chart title
    script << "set xlabel 'Date'\n";
    script << "set ylabel 'Price'\n";
    script << "set style data candlesticks\n"; // Enable candlestick style
    script << "set boxwidth 0.6 relative\n";   // Set candlestick width
    script << "set style fill solid 0.3\n";    // Candlestick fill style

    // script << "set xtics rotate by 45 font ',7'\n";
    script << "set font ',7'\n";
    script << "set bmargin 5\n";  // Increase bottom margin
    script << "set rmargin 10\n"; // Increase bottom margin

    script << "set datafile separator ','\n";

    script << "set style fill solid 1.0 border -1\n";
    script << "set boxwidth 0.6 relative\n";
    script << "set style line 1 lc rgb '#00FF00'\n";
    script << "set style line 2 lc rgb '#FF0000'\n";

    script << "plot '" << dataFile << "' using 1:2:3:4:5:(($5 > $2) ? 2 : 1) with candlesticks \\\n";
    script << "     linecolor variable fillstyle solid title '' whiskerbars\n";
    script.close();

    // Execute gnuplot script
    std::string command = "gnuplot -persistent " + gnuplotScript;
    if (system(command.c_str()) != 0)
    {
        std::cerr << "Error: Failed to execute gnuplot" << std::endl;
    }

    // Cleanup script file
    std::remove(gnuplotScript.c_str());
}

int main()
{
    const std::string dataFile = "market_data.csv"; // Change this to the path of your CSV file
    CandlestickChart(dataFile);
    return 0;
}
