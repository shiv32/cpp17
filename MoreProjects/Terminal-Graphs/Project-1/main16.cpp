#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <random>
#include <algorithm>
#include <iomanip>

using namespace std;

const int WIDTH  = 30;  // Number of columns
const int HEIGHT = 10;  // Height of the graph

void drawGraph(const vector<int>& data) {
    cout << "\033[2J\033[H"; // Clear screen

    int maxVal = *max_element(data.begin(), data.end());
    if (maxVal == 0) maxVal = 1;

    // Draw graph rows
    for (int row = HEIGHT; row > 0; --row) {
        int level = (maxVal * row) / HEIGHT;
        cout << setw(4) << level << " | ";
        for (int val : data) {
            int barHeight = (val * HEIGHT) / maxVal;
            cout << (barHeight >= row ? "|" : " ") << " ";
        }
        cout << "\n";
    }

    // X-axis line
    cout << "     +";
    for (int i = 0; i < WIDTH * 2; ++i) cout << "-";
    cout << "\n";

    // X-axis labels:
    // Show 0, middle, and max (WIDTH-1)
    cout << "     ";
    for (int i = 0; i < WIDTH; ++i) {
        if (i == 0)
            cout << "0 ";
        else if (i == WIDTH - 1)
            cout << (WIDTH - 1) << " ";  // max at right
        else if (i == WIDTH / 2)
            cout << (WIDTH / 2) << " ";  // middle label
        else
            cout << "  "; // blank for other positions
    }
    cout << "\n";
}

int main() {
    vector<int> data(WIDTH, 0);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 100);

    while (true) {
        // Shift values right
        for (int i = WIDTH - 1; i > 0; --i)
            data[i] = data[i - 1];

        // New value at index 0
        data[0] = dist(gen);

        drawGraph(data);
        cout << "\nNewest data at x=0 (left). Oldest at x=" << WIDTH-1 << " (right)\n";

        this_thread::sleep_for(1s);
    }
}
