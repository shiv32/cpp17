/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief  Algorithmic trading
 
            Read market_data.csv and draw graph using gnuplot.

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

void plotStockData(const std::string &dataFile)
{
    const std::string gnuplotScript = "stock_plot.gp";

    // Write gnuplot script
    std::ofstream script(gnuplotScript);
    if (!script.is_open())
    {
        std::cerr << "Error: Unable to create gnuplot script file" << std::endl;
        return;
    }

    //-------------------------------------------
    //script << "set terminal wxt size 1600,800\n"; // Enable the default interactive terminal
    script << "set terminal qt size 1600,800\n"; // Enable the default interactive terminal
    script << "set title 'Stock Data'\n";
    script << "set xlabel 'Date'\n";
    script << "set ylabel 'Price'\n";
    script << "set xdata time\n";

    // script << "set timefmt '%Y-%m-%d'\n"; //2023-01-01 Input date format in the CSV file
    // script << "set format x '%Y-%m-%d'\n"; // Output date format on X-axis

    script << "set timefmt '%d-%b-%Y'\n";  // 04-Dec-2024 Input date format in the CSV file
    script << "set format x '%d-%b-%Y'\n"; // Output date format on X-axis

    script << "set xtics rotate by 45 font ',7'\n";
    script << "set bmargin 5\n";  // Increase bottom margin
    script << "set rmargin 10\n"; // Increase bottom margin
    script << "set grid\n";
    script << "set key top right\n"; // Legend at the top-right corner
    script << "set datafile separator ','\n";

    script << "plot '" << dataFile << "' using 1:2 title 'Open' with lines linecolor rgb '#FF0000', \\\n"; // Red
    script << "     '" << dataFile << "' using 1:3 title 'High' with lines linecolor rgb '#0000FF', \\\n"; // Blue
    script << "     '" << dataFile << "' using 1:4 title 'Low' with lines linecolor rgb '#00FF00', \\\n";  // Green
    script << "     '" << dataFile << "' using 1:5 title 'Close' with lines linecolor rgb '#FFA500'\n";    // Orange

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
    plotStockData(dataFile);
    return 0;
}

