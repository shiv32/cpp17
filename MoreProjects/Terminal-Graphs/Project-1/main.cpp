#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

int main() {
    // Generate data: y = x^2 for x = 1..10
    std::vector<std::pair<int,int>> points;
    for (int x=1; x<=10; ++x)
        points.emplace_back(x, x*x);

    const int width = 40;
    const int height = 20;

    int maxX = 0, maxY = 0;
    for (auto [x,y] : points) {
        maxX = std::max(maxX,x);
        maxY = std::max(maxY,y);
    }

    // Grid of dots
    std::vector<std::string> grid(height+1, std::string(width+6, '.'));

    // Plot data points only
    for (auto [x,y]: points) {
        int gx = static_cast<int>((double)x/maxX * width);
        int gy = static_cast<int>((double)y/maxY * height);
        gy = height - gy; // invert y
        grid[gy][5+gx] = '*';
    }

    // Print with Y-axis numeric labels
    for (int row=0; row<=height; ++row) {
        int yValue = static_cast<int>((double)(height-row)/height * maxY);
        if (row % 5 == 0)
            std::cout << std::setw(4) << yValue << " " << grid[row] << "\n";
        else
            std::cout << "     " << grid[row] << "\n";
    }

    // Print X labels only as numbers
    std::cout << "      ";
    for (int i=0; i<=width; i+=width/maxX) {
        int xValue = static_cast<int>((double)i/width * maxX + 0.5);
        std::cout << std::setw(width/maxX) << xValue;
    }
    std::cout << "\n";
}
