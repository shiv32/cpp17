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

// A function to draw a single graph from data
void drawGraph(const std::vector<int>& data,
               const std::string& title,
               int width, int height,
               int maxX, int maxBandwidth)
{
    // Prepare grid
    std::vector<std::string> grid(height+1, std::string(width+6, '.'));

    // Plot data
    for (int i = 0; i < (int)data.size(); ++i) {
        int gx = static_cast<int>((double)i / maxX * width);
        int gy = static_cast<int>((double)data[i] / maxBandwidth * height);
        gy = height - gy;
        if (gy >= 0 && gy <= height)
            grid[gy][5 + gx] = '*';
    }

    // Print grid with Y labels
    for (int row = 0; row <= height; ++row) {
        int yVal = (int)((double)(height - row) / height * maxBandwidth);
        if (row % 5 == 0)
            std::cout << std::setw(4) << yVal << " " << grid[row] << "\n";
        else
            std::cout << "     " << grid[row] << "\n";
    }

    // Title
    std::cout << "(" << title << " KB/s)\n\n";
}

int main() {
    const int width = 60;       // graph width
    const int height = 15;      // graph height
    const int maxX = 60;        // samples shown
    const int maxBandwidth = 1000; // max KB/s simulated

    std::vector<int> rxData, txData;
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, maxBandwidth);

    while (true) {
        // Generate random bandwidth values
        rxData.push_back(dist(rng));
        txData.push_back(dist(rng));

        // Sliding window
        if ((int)rxData.size() > maxX) rxData.erase(rxData.begin());
        if ((int)txData.size() > maxX) txData.erase(txData.begin());

        clearScreen();

        // Draw RX graph
        drawGraph(rxData, "RX", width, height, maxX, maxBandwidth);

        // Draw TX graph
        drawGraph(txData, "TX", width, height, maxX, maxBandwidth);

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}
