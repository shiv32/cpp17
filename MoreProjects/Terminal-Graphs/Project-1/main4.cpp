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

int main() {
    const int width = 30;    // graph width for each panel
    const int height = 20;   // graph height
    const int maxX = 60;     // samples per panel
    const int maxBandwidth = 1000; // max KB/s

    // Gap between two graphs
    const int gap = 15; // space columns between RX and TX panels

    std::vector<int> rxData, txData;
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, maxBandwidth);

    while (true) {
        // Generate simulated RX/TX values
        rxData.push_back(dist(rng));
        txData.push_back(dist(rng));

        // Keep only last maxX samples
        if ((int)rxData.size() > maxX) rxData.erase(rxData.begin());
        if ((int)txData.size() > maxX) txData.erase(txData.begin());

        // Prepare empty grid
        std::vector<std::string> grid(height+1, std::string(width*2 + gap + 10, '.'));

        // Lambda to plot data into grid
        auto plot = [&](const std::vector<int>& data, int offset) {
            for (int i = 0; i < (int)data.size(); ++i) {
                int gx = static_cast<int>((double)i / maxX * width);
                int gy = static_cast<int>((double)data[i] / maxBandwidth * height);
                gy = height - gy;
                if (gy >= 0 && gy <= height)
                    grid[gy][offset + gx] = '*';
            }
        };

        // Plot RX (left) and TX (right) with a bigger gap
        int leftOffset = 6;
        int rightOffset = 6 + width + gap;
        plot(rxData, leftOffset);
        plot(txData, rightOffset);

        clearScreen();

        // Print graph rows with Y-axis labels
        for (int row = 0; row <= height; ++row) {
            int yVal = (int)((double)(height - row) / height * maxBandwidth);
            if (row % 5 == 0)
                std::cout << std::setw(4) << yVal << " " << grid[row] << "\n";
            else
                std::cout << "     " << grid[row] << "\n";
        }

        // Labels under the two graphs
        std::cout << "\n(RX KB/s)";
        std::cout << std::setw(width + gap + 6) << "";
        std::cout << "(TX KB/s)\n";

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}
