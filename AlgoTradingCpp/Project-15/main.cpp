#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <cmath>

float calculateRSI(const std::vector<float> &prices, int period = 14)
{
    if (prices.size() <= period)
        return 0.0f;

    float gain = 0.0f, loss = 0.0f;
    for (size_t i = prices.size() - period; i < prices.size() - 1; ++i)
    {
        float diff = prices[i + 1] - prices[i];
        if (diff >= 0)
            gain += diff;
        else
            loss -= diff;
    }

    if (loss == 0)
        return 100.0f; // Prevent divide by 0
    float rs = gain / loss;
    return 100.0f - (100.0f / (1 + rs));
}

void drawRSIChart(const std::vector<float> &prices, int period = 14)
{
    std::cout << "\nRSI Chart (Last " << prices.size() << " prices):\n";
    std::cout << "----------------------------------------\n";

    const int chartHeight = 10;
    const int overbought = 70;
    const int oversold = 30;

    for (size_t i = period; i < prices.size(); ++i)
    {
        float rsi = calculateRSI(std::vector<float>(prices.begin(), prices.begin() + i), period);

        std::string level;
        if (rsi >= overbought)
            level = "OVERBOUGHT";
        else if (rsi <= oversold)
            level = "OVERSOLD";
        else
            level = "NEUTRAL";

        int bar = static_cast<int>((rsi / 100.0f) * chartHeight);
        std::cout << std::setw(2) << i << " | " << std::setw(6) << std::fixed << std::setprecision(2) << rsi << " | ";
        for (int j = 0; j < bar; ++j)
            std::cout << "=";
        std::cout << "  ← " << level << "\n";
    }

    std::cout << "----------------------------------------\n";
    std::cout << "[30=Oversold] [70=Overbought] (0–100 scale)\n\n";
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    
    std::vector<float> samplePrices = {
        100, 101, 102, 103, 102, 101, 100,
        98, 99, 100, 102, 104, 105, 106,
        108, 109, 110, 112, 114, 116, 117, 115, 113, 110};

    drawRSIChart(samplePrices);

    return 0;
}
