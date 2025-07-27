#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <thread>
#include <chrono>
#include <random>

void clearScreen() {
    std::cout << "\033[2J\033[H";
}

void drawGraph(const std::vector<int>& data,
               const std::string& title,
               int width, int height,
               int maxX, int maxBandwidth,
               int startSec)
{
    // Create empty grid
    std::vector<std::string> grid(height+1, std::string(width+6, '.'));

    // Plot data points
    for (int i = 0; i < (int)data.size(); ++i) {
        int gx = static_cast<int>((double)i / maxX * width);
        int gy = static_cast<int>((double)data[i] / maxBandwidth * height);
        gy = height - gy;
        if (gy >= 0 && gy <= height)
            grid[gy][5 + gx] = '*';
    }

    // Print Y labels and graph
    for (int row = 0; row <= height; ++row) {
        int yVal = (int)((double)(height - row) / height * maxBandwidth);
        if (row % 5 == 0)
            std::cout << std::setw(4) << yVal << " " << grid[row] << "\n";
        else
            std::cout << "     " << grid[row] << "\n";
    }

    // Print X-axis labels as seconds
    std::cout << "      ";
    for (int i = 0; i <= width; i += width / 10) {
        int secLabel = startSec + (int)((double)i / width * maxX + 0.5);
        std::cout << std::setw(width / 10) << secLabel;
    }
    std::cout << "\n";

    // Graph title
    std::cout << "(" << title << " KB/s)\n\n";
}

int main() {
    const int width = 60;        // width of the graph
    const int height = 15;       // height of each graph
    const int maxSec = 60;       // visible seconds on X-axis
    const int maxBandwidth = 1000; // maximum simulated KB/s

    std::vector<int> rxData, txData;
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, maxBandwidth);

    int sec = 0;

    while (true) {
        // Simulate new data point
        rxData.push_back(dist(rng));
        txData.push_back(dist(rng));
        ++sec;

        // Sliding window for the last maxSec points
        if ((int)rxData.size() > maxSec) rxData.erase(rxData.begin());
        if ((int)txData.size() > maxSec) txData.erase(txData.begin());

        // Determine starting second for X-axis
        int startSec = std::max(0, sec - maxSec + 1);

        clearScreen();

        // Draw RX and TX graphs
        drawGraph(rxData, "RX", width, height, maxSec, maxBandwidth, startSec);
        drawGraph(txData, "TX", width, height, maxSec, maxBandwidth, startSec);

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
