#include <string>
#include <queue>
#include <iostream>
#include <fstream>
#include <sstream>

// Tick Model
struct Tick
{
    std::string symbol;
    double price;
    int quantity;
};

// Market Data Handler
class MarketDataHandler
{
private:
    std::queue<double> window;
    int windowSize;
    double sum = 0.0;

public:
    MarketDataHandler(int size) : windowSize(size) {}

    void onTick(const Tick &tick)
    {
        // Maintain moving average
        window.push(tick.price);
        sum += tick.price;

        if (window.size() > windowSize)
        {
            sum -= window.front();
            window.pop();
        }

        double movingAvg = sum / window.size();

        std::cout << "Symbol: " << tick.symbol
                  << " Price: " << tick.price
                  << " MA(" << windowSize << "): " << movingAvg
                  << "\n";
    }
};

// Main (Streaming Simulation)
int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::ifstream file("../ticks.txt"); // Input Data (Simulated Feed)
    
    MarketDataHandler handler(3);

    std::string line;

    while (std::getline(file, line))
    {
        std::stringstream ss(line);

        Tick tick;
        ss >> tick.symbol >> tick.price >> tick.quantity;

        handler.onTick(tick);
    }

    return 0;
}