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
    const int width = 30;    // graph width per panel
    const int height = 20;   // graph height
    const int maxX = 60;     // number of samples in sliding window
    const int maxBandwidth = 1000; // max simulated bandwidth in KB/s

    std::vector<int> rxData, txData;
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, maxBandwidth);

    while (true) {
        // Generate random data for RX and TX
        int rx = dist(rng);
        int tx = dist(rng);

        rxData.push_back(rx);
        txData.push_back(tx);

        // Keep sliding window
        if ((int)rxData.size() > maxX) rxData.erase(rxData.begin());
        if ((int)txData.size() > maxX) txData.erase(txData.begin());

        // Prepare grid for RX and TX
        std::vector<std::string> grid(height+1, std::string(width*2+12, '.'));

        auto plot = [&](const std::vector<int>& data, int offset) {
            int size = data.size();
            for (int i = 0; i < size; ++i) {
                double normX = (double)i / maxX * width;
                int gx = static_cast<int>(normX);
                int gy = static_cast<int>((double)data[i]/maxBandwidth * height);
                gy = height - gy;
                if (gy < 0) gy = 0;
                if (gy >= 0 && gy <= height)
                    grid[gy][offset+gx] = '*';
            }
        };

        // Plot RX (left) and TX (right)
        plot(rxData, 6);               // left panel starting at column 6
        plot(txData, 6 + width + 6);   // right panel

        clearScreen();

        // Print graphs with Y labels
        for (int row = 0; row <= height; ++row) {
            int yVal = (int)((double)(height-row)/height * maxBandwidth);
            if (row % 5 == 0)
                std::cout << std::setw(4) << yVal << " " << grid[row] << "\n";
            else
                std::cout << "     " << grid[row] << "\n";
        }

        // Print RX and TX labels
        std::cout << "\n(RX KB/s)" << std::setw(width+6) << "" << "(TX KB/s)\n";

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}
