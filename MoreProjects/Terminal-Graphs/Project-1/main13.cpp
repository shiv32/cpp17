#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <random>
#include <algorithm>
#include <iomanip>

using namespace std;

const int WIDTH  = 30;  // columns (time steps)
const int HEIGHT = 10;  // max vertical bars

void drawGraph(const vector<int>& data) {
    // Clear screen
    cout << "\033[2J\033[H";

    // Find max value for scaling
    int maxVal = *max_element(data.begin(), data.end());
    if (maxVal == 0) maxVal = 1;

    // Draw from top to bottom
    for (int row = HEIGHT; row > 0; --row) {
        int yValue = (maxVal * row) / HEIGHT;
        cout << setw(4) << yValue << " | ";  // Y-axis label
        for (int val : data) {
            int barHeight = (val * HEIGHT) / maxVal;
            cout << (barHeight >= row ? "|" : " ") << " ";
        }
        cout << "\n";
    }

    // Draw X-axis line
    cout << "     +";
    for (int i = 0; i < WIDTH * 2; ++i) cout << "-";
    cout << "\n";

    // Draw X-axis labels (seconds)
    cout << "       ";
    for (int i = 0; i < WIDTH; ++i)
        cout << (i % 10) << " ";  // modulo 10 for readability
    cout << "\n";
}

int main() {
    vector<int> data(WIDTH, 0);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 100); // simulated bandwidth

    while (true) {
        // shift data left (oldest goes out on left)
        for (size_t i = 1; i < data.size(); ++i)
            data[i - 1] = data[i];

        // put new sample on the right
        data.back() = dist(gen);

        drawGraph(data);
        cout << "\nSimulated Network Bandwidth (units)\n";

        this_thread::sleep_for(1s);
    }
    return 0;
}
