/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief  Algorithmic trading
     
     Test gnuplot graph for data visualization

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

void plotSinX()
{
    const std::string gnuplotScript = "sinx_plot.gp";

    // Write gnuplot script
    std::ofstream script(gnuplotScript);
    if (!script.is_open())
    {
        std::cerr << "Error: Unable to create gnuplot script file" << std::endl;
        return;
    }

    script << "set terminal wxt\n";                      // Set graphical terminal
    script << "set title 'Plot of sin(x)'\n";            // Set graph title
    script << "set xlabel 'x'\n";                        // Set X-axis label
    script << "set ylabel 'sin(x)'\n";                   // Set Y-axis label
    script << "set grid\n";                              // Enable grid
    script << "plot sin(x) title 'sin(x)' with lines\n"; // Plot sin(x)
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
    plotSinX();
    return 0;
}
