#include <iostream>
#include <vector>
#include <string>

// ============================
// CRTP Engine Base
// ============================
template <typename Strategy>
class Engine
{
public:
    void run()
    {
        std::cout << "Engine started...\n";

        // Simulated market ticks
        std::vector<double> prices = {100.5, 101.2, 99.8, 102.1};

        for (double price : prices)
        {
            // Call derived strategy
            static_cast<Strategy *>(this)->onTick(price);
        }

        std::cout << "Engine finished.\n";
    }
};

// ============================
// Strategy 1: Print Strategy
// ============================
class PrintStrategy : public Engine<PrintStrategy>
{
public:
    void onTick(double price)
    {
        std::cout << "Price: " << price << "\n";
    }
};

// ============================
// Strategy 2: Simple Buy Strategy
// ============================
class BuyBelowStrategy : public Engine<BuyBelowStrategy>
{
private:
    double threshold = 100.0;

public:
    void onTick(double price)
    {
        if (price < threshold)
        {
            std::cout << "BUY at " << price << "\n";
        }
        else
        {
            std::cout << "No action at " << price << "\n";
        }
    }
};

// ============================
// Main
// ============================
int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::cout << "=== Print Strategy ===\n";
    PrintStrategy s1;
    s1.run();

    std::cout << "\n=== Buy Strategy ===\n";
    BuyBelowStrategy s2;
    s2.run();

    return 0;
}
