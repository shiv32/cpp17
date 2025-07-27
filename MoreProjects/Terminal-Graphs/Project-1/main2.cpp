#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <thread>
#include <chrono>

// Function to clear screen (ANSI escape)
void clearScreen() {
    std::cout << "\033[2J\033[H";
}

int main() {
    const int width = 40;
    const int height = 20;
    const int maxX = 50;       // plot 1..50
    const int maxY = maxX*maxX;

    std::vector<std::pair<int,int>> points;

    for (int currentX = 1; currentX <= maxX; ++currentX) {
        points.emplace_back(currentX, currentX*currentX);

        // Prepare grid
        std::vector<std::string> grid(height+1, std::string(width+6, '.'));

        // Plot all points so far
        for (auto [x,y]: points) {
            int gx = static_cast<int>((double)x/maxX * width);
            int gy = static_cast<int>((double)y/maxY * height);
            gy = height - gy; // invert y
            if (gy >= 0 && gy <= height)
                grid[gy][5+gx] = '*';
        }

        clearScreen();

        // Print grid with Y-axis labels
        for (int row=0; row<=height; ++row) {
            int yValue = static_cast<int>((double)(height-row)/height * maxY);
            if (row % 5 == 0)
                std::cout << std::setw(4) << yValue << " " << grid[row] << "\n";
            else
                std::cout << "     " << grid[row] << "\n";
        }

        // Print X labels
        std::cout << "      ";
        for (int i=0; i<=width; i+=width/10) {
            int xValue = static_cast<int>((double)i/width * maxX + 0.5);
            std::cout << std::setw(width/10) << xValue;
        }
        std::cout << "\n";

        std::this_thread::sleep_for(std::chrono::milliseconds(300)); // delay
    }

    return 0;
}
