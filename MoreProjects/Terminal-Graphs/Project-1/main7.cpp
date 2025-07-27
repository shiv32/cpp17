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
               int maxSec, int maxBandwidth)
{
    // Empty grid
    std::vector<std::string> grid(height+1, std::string(width+6, '.'));

    // Plot points: newest on the right, oldest on the left
    int size = data.size();
    for (int i = 0; i < size; ++i) {
        int indexFromRight = size - 1 - i; // 0 = newest, max = oldest
        int gx = width - 1 - static_cast<int>((double)indexFromRight / maxSec * width);
        int gy = static_cast<int>((double)data[size - 1 - indexFromRight] / maxBandwidth * height);
        gy = height - gy;
        if (gx >= 0 && gx < width && gy >= 0 && gy <= height)
            grid[gy][5 + gx] = '*';
    }

    // Draw graph rows
    for (int row = 0; row <= height; ++row) {
        int yVal = static_cast<int>((double)(height - row) / height * maxBandwidth);
        if (row % 5 == 0)
            std::cout << std::setw(4) << yVal << " " << grid[row] << "\n";
        else
            std::cout << "     " << grid[row] << "\n";
    }

    // Print fixed X-axis labels (always 0..maxSec)
    std::cout << "      ";
    for (int i = 0; i <= width; i += width / 10) {
        int secLabel = (int)((double)i / width * maxSec);
        std::cout << std::setw(width / 10) << secLabel;
    }
    std::cout << "\n";

    // Title
    std::cout << "(" << title << " KB/s)\n\n";
}

int main() {
    const int width = 60;       // graph width
    const int height = 15;      // graph height
    const int maxSec = 60;      // seconds displayed (window size)
    const int maxBandwidth = 1000; // max bandwidth scale

    std::vector<int> rxData, txData;
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, maxBandwidth);

    while (true) {
        // Simulate new RX/TX sample
        rxData.push_back(dist(rng));
        txData.push_back(dist(rng));

        // Keep fixed-size window (maxSec)
        if ((int)rxData.size() > maxSec) rxData.erase(rxData.begin());
        if ((int)txData.size() > maxSec) txData.erase(txData.begin());

        clearScreen();

        drawGraph(rxData, "RX", width, height, maxSec, maxBandwidth);
        drawGraph(txData, "TX", width, height, maxSec, maxBandwidth);

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
