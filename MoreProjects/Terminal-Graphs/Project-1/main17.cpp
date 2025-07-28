#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <random>
#include <algorithm>
#include <iomanip>

using namespace std;

const int WIDTH  = 30;
const int HEIGHT = 10;

void drawGraph(const vector<int>& data) {
    // Move cursor to top-left (no need to clear full screen every time)
    cout << "\033[H";

    int maxVal = *max_element(data.begin(), data.end());
    if (maxVal == 0) maxVal = 1;

    for (int row = HEIGHT; row > 0; --row) {
        int level = (maxVal * row) / HEIGHT;
        cout << setw(4) << level << " | ";
        for (int val : data) {
            int barHeight = (val * HEIGHT) / maxVal;
            cout << (barHeight >= row ? "|" : " ") << " ";
        }
        cout << "\n";
    }

    cout << "     +";
    for (int i = 0; i < WIDTH * 2; ++i) cout << "-";
    cout << "\n";

    // Labels: 0, mid, max
    cout << "     ";
    for (int i = 0; i < WIDTH; ++i) {
        if (i == 0)
            cout << "0 ";
        else if (i == WIDTH / 2)
            cout << WIDTH / 2 << " ";
        else if (i == WIDTH - 1)
            cout << WIDTH - 1 << " ";
        else
            cout << "  ";
    }
    cout << "\n";
}

int main() {
    // Enter alternate screen (no history mode)
    std::cout << "\033[?1049h";

    vector<int> data(WIDTH, 0);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 100);

    while (true) {
        // Shift right
        for (int i = WIDTH - 1; i > 0; --i)
            data[i] = data[i - 1];
        data[0] = dist(gen);

        drawGraph(data);
        cout << "\nNewest data at x=0 (left), oldest at x=" << WIDTH-1 << " (right)\n";

        this_thread::sleep_for(1s);
    }

    // Exit alternate screen (never reached in this demo)
    std::cout << "\033[?1049l";
}
