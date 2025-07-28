#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;

const int WIDTH = 30;   // number of time steps (X-axis)
const int HEIGHT = 10;  // max graph height (Y-axis)

void drawGraph(const vector<int>& data) {
    // Clear screen
    cout << "\033[2J\033[H"; // ANSI escape to clear and move cursor to home

    int maxVal = *max_element(data.begin(), data.end());
    if (maxVal == 0) maxVal = 1;

    // Draw top to bottom (HEIGHT rows)
    for (int row = HEIGHT; row > 0; --row) {
        for (int val : data) {
            int barHeight = (val * HEIGHT) / maxVal;
            if (barHeight >= row)
                cout << "| ";
            else
                cout << "  ";
        }
        cout << "\n";
    }

    // Draw X-axis
    for (int i = 0; i < WIDTH; ++i) cout << "--";
    cout << "\n";
}

int main() {
    vector<int> data(WIDTH, 0);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 100); // Simulated bandwidth

    while (true) {
        // Shift data left
        for (size_t i = 1; i < data.size(); ++i)
            data[i - 1] = data[i];
        // Add new value on right
        data.back() = dist(gen);

        drawGraph(data);
        cout << "Simulated Network Bandwidth (units)\n";

        this_thread::sleep_for(1s);
    }

    return 0;
}
