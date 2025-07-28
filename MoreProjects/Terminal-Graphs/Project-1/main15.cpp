#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <random>
#include <algorithm>
#include <iomanip>

using namespace std;

const int WIDTH  = 30;  // X-axis (0 = newest)
const int HEIGHT = 10;  // Y-axis

void drawGraph(const vector<int>& data) {
    cout << "\033[2J\033[H"; // Clear screen

    int maxVal = *max_element(data.begin(), data.end());
    if (maxVal == 0) maxVal = 1;

    // Top to bottom drawing
    for (int row = HEIGHT; row > 0; --row) {
        int level = (maxVal * row) / HEIGHT;
        cout << setw(4) << level << " | ";
        // Draw left to right (0 = newest)
        for (int val : data) {
            int barHeight = (val * HEIGHT) / maxVal;
            cout << (barHeight >= row ? "|" : " ") << " ";
        }
        cout << "\n";
    }

    // X-axis line
    cout << "   0 +";
    for (int i = 0; i < WIDTH * 2; ++i) cout << "-";
    cout << "\n";

    // X-axis labels (0 = newest on left)
    cout << "      ";
    for (int i = 0; i < WIDTH; ++i)
        cout << i % 10 << " ";
    cout << "\n";
}

int main() {
    vector<int> data(WIDTH, 0);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 100);

    while (true) {
        // Shift data right
        for (int i = WIDTH - 1; i > 0; --i)
            data[i] = data[i - 1];

        // Newest sample goes at index 0
        data[0] = dist(gen);

        drawGraph(data);
        cout << "\nNewest data at x=0 (left). Oldest at right.\n";

        this_thread::sleep_for(1s);
    }
}
