#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <random>
#include <algorithm>
#include <iomanip>

using namespace std;

const int WIDTH  = 30;  // X-axis: time steps
const int HEIGHT = 10;  // Y-axis: graph height

void drawGraph(const vector<int>& data) {
    cout << "\033[2J\033[H"; // Clear screen

    int maxVal = *max_element(data.begin(), data.end());
    if (maxVal == 0) maxVal = 1;

    // Draw from top to bottom (HEIGHT rows)
    for (int row = HEIGHT; row > 0; --row) {
        int level = (maxVal * row) / HEIGHT;
        cout << setw(4) << level << " | ";
        for (int val : data) {
            int barHeight = (val * HEIGHT) / maxVal;
            cout << (barHeight >= row ? "|" : " ") << " ";
        }
        cout << "\n";
    }

    // Draw X-axis
    cout << "   0 +";
    for (int i = 0; i < WIDTH * 2; ++i) cout << "-";
    cout << "\n";

    // X-axis labels (time steps 0..WIDTH-1)
    cout << "      ";
    for (int i = 0; i < WIDTH; ++i)
        cout << (i % 10) << " ";
    cout << "\n";
}

int main() {
    vector<int> data(WIDTH, 0);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 100); // simulated bandwidth

    int t = 0;
    while (true) {
        // Shift left
        for (size_t i = 1; i < data.size(); ++i)
            data[i - 1] = data[i];

        // New value at right
        data.back() = dist(gen);

        drawGraph(data);
        cout << "\nSimulated Network Bandwidth (0 = oldest, right = latest)\n";
        ++t;

        this_thread::sleep_for(1s);
    }
    return 0;
}
