/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief  Algorithmic trading

            Read market_data.csv and draw CandlestickChart With Volume Chart using gnuplot.

 * @version 0.1
 * @date 2024-10-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <fstream>
#include <iostream>
#include <string>

void CandlestickChartWithVolume(const std::string &dataFile)
{
    const std::string gnuplotScript = "stock_plot.gp";

    // Write gnuplot script
    std::ofstream script(gnuplotScript);
    if (!script.is_open())
    {
        std::cerr << "Error: Unable to create gnuplot script file" << std::endl;
        return;
    }

    // script << "set terminal qt size 1600,800 enhanced title 'Candlestick Chart with Volume'\n";
    script << "set terminal qt size 1600,800'\n";
    script << "set xdata time\n";

    // script << "set timefmt '%Y-%m-%d'\n"; //2023-01-01 Input date format in the CSV file
    // script << "set format x '%Y-%m-%d'\n"; // Output date format on X-axis
    script << "set timefmt '%d-%b-%Y'\n";  // 04-Dec-2024 Input date format in the CSV file
    script << "set format x '%d-%b-%Y'\n"; // Output date format on X-axis

    script << "set grid\n";
    script << "set multiplot layout 2,1 title 'Candlestick Chart with Volume'\n";

    // First plot: Candlestick chart
    script << "set margins 10,10,1,1\n";
    script << "set xlabel ''\n";
    script << "set xtics format ''\n";
    // script << "set xtics format '%d-%b-%Y' rotate by 45 right\n";
    script << "set ylabel 'Price'\n";
    script << "unset y2tics\n";
    script << "set style line 1 lc rgb '#00FF00'\n";
    script << "set style line 2 lc rgb '#FF0000'\n";
    script << "set datafile separator ','\n";
    script << "plot '" << dataFile << "' using 1:2:3:4:5:($5 > $2 ? 1 : 2) with candlesticks lc variable title 'OHLC'\n";

    // Second plot: Volume chart
    script << "set margins 10,10,8,0\n"; // R,L,B,T
    script << "set xlabel 'Date'\n";
    // script << "set xtics format '%Y-%m-%d' rotate by 45 right\n";
    script << "set xtics format '%d-%b-%Y' rotate by 45 right\n";
    script << "set ylabel 'Volume'\n";
    script << "set style fill solid 1.0 border -1\n";
    script << "set boxwidth 0.5 relative\n";
    script << "set y2tics\n";
    script << "set y2range [0:*]\n";
    script << "set datafile separator ','\n";
    script << "plot '" << dataFile << "' using 1:($6/1000):($5 > $2 ? 1 : 2) with boxes lc variable title 'Volume'\n";

    script << "unset multiplot\n";

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
    CandlestickChartWithVolume(dataFile);
    return 0;
}
