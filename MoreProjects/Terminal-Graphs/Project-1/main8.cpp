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
    std::vector<std::string> grid(height+1, std::string(width+6, '.'));

    int size = data.size();
    // index 0 = newest, shown on the left
    for (int i = 0; i < size; ++i) {
        int gx = static_cast<int>((double)i / maxSec * width); // i=0 goes to left
        int gy = static_cast<int>((double)data[i] / maxBandwidth * height);
        gy = height - gy;
        if (gx >= 0 && gx < width && gy >= 0 && gy <= height)
            grid[gy][5 + gx] = '*';
    }

    // Print graph with Y labels
    for (int row = 0; row <= height; ++row) {
        int yVal = static_cast<int>((double)(height - row) / height * maxBandwidth);
        if (row % 5 == 0)
            std::cout << std::setw(4) << yVal << " " << grid[row] << "\n";
        else
            std::cout << "     " << grid[row] << "\n";
    }

    // Print fixed X-axis labels
    std::cout << "      ";
    for (int i = 0; i <= width; i += width / 10) {
        int secLabel = (int)((double)i / width * maxSec);
        std::cout << std::setw(width / 10) << secLabel;
    }
    std::cout << "\n";

    std::cout << "(" << title << " KB/s)\n\n";
}

int main() {
    const int width = 60;
    const int height = 15;
    const int maxSec = 60;
    const int maxBandwidth = 1000;

    std::vector<int> rxData, txData;
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, maxBandwidth);

    while (true) {
        // Generate new sample
        int newRx = dist(rng);
        int newTx = dist(rng);

        // Insert at the beginning (index 0 = newest)
        rxData.insert(rxData.begin(), newRx);
        txData.insert(txData.begin(), newTx);

        // Keep only last maxSec samples
        if ((int)rxData.size() > maxSec) rxData.pop_back();
        if ((int)txData.size() > maxSec) txData.pop_back();

        clearScreen();

        drawGraph(rxData, "RX", width, height, maxSec, maxBandwidth);
        drawGraph(txData, "TX", width, height, maxSec, maxBandwidth);

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
