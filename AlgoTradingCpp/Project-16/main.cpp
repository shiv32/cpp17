#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdexcept>

// =======================
// Data Model
// =======================
struct Candle {
    std::string date;
    double open{};
    double high{};
    double low{};
    double close{};
    long long volume{};
    double turnover{};
};

// =======================
// CSV Loader (change CSV format here only)
// =======================
std::vector<Candle> loadCSV(const std::string& file) {
    std::ifstream in(file);
    if (!in)
        throw std::runtime_error("CSV file not found");

    std::vector<Candle> data;
    std::string line;

    std::getline(in, line); // skip header

    while (std::getline(in, line)) {
        std::stringstream ss(line);
        Candle c;
        std::string temp;

        std::getline(ss, c.date, ',');
        std::getline(ss, temp, ','); c.open = std::stod(temp);
        std::getline(ss, temp, ','); c.high = std::stod(temp);
        std::getline(ss, temp, ','); c.low  = std::stod(temp);
        std::getline(ss, temp, ','); c.close = std::stod(temp);
        std::getline(ss, temp, ','); c.volume = std::stoll(temp);
        std::getline(ss, temp, ','); c.turnover = std::stod(temp);

        data.push_back(c);
    }
    return data;
}

// =======================
// Strategy Interface
// =======================
struct Strategy {
    virtual ~Strategy() = default;
    virtual double onBar(const Candle& prev,
                         const Candle& curr) = 0;
};

// =======================
// Strategy 1: Momentum (Close-to-Close)
// =======================
struct MomentumStrategy : Strategy {
    double onBar(const Candle& prev,
                 const Candle& curr) override {
        if (curr.close > prev.close)
            return curr.close - prev.close;
        return 0.0;
    }
};

// =======================
// Strategy 2: Range Breakout
// =======================
struct RangeBreakoutStrategy : Strategy {
    double onBar(const Candle& prev,
                 const Candle& curr) override {
        if (curr.high > prev.high)
            return curr.close - prev.high;
        return 0.0;
    }
};

// Strategy 3: sma 
struct SMAStrategy : Strategy {
    size_t window;
    std::vector<double> closes;

    explicit SMAStrategy(size_t w = 5) : window(w) {}

    double onBar(const Candle& prev,
                 const Candle& curr) override {

        closes.push_back(curr.close);

        if (closes.size() < window)
            return 0.0;

        double sum = 0.0;
        for (size_t i = closes.size() - window; i < closes.size(); ++i)
            sum += closes[i];

        double sma = sum / window;

        if (curr.close > sma)
            return curr.close - prev.close;

        return 0.0;
    }
};

// =======================
// Backtest Engine (NEVER changes)
// =======================
class BacktestEngine {
    Strategy& strategy;

public:
    explicit BacktestEngine(Strategy& s) : strategy(s) {}

    double run(const std::vector<Candle>& data) {
        if (data.size() < 2) return 0.0;

        double pnl = 0.0;
        for (size_t i = 1; i < data.size(); ++i) {
            pnl += strategy.onBar(data[i - 1], data[i]);
        }
        return pnl;
    }
};

// =======================
// main()
// =======================
int main() {
    try {
        auto candles = loadCSV("../Data/nifty.csv");

        //Swap strategy here
        MomentumStrategy strategy;
        //RangeBreakoutStrategy strategy;
        //SMAStrategy strategy(5);   // 5-day SMA

        BacktestEngine engine(strategy);
        double pnl = engine.run(candles);

        std::cout << "Bars processed : " << candles.size() << "\n";
        std::cout << "Total PnL      : " << pnl << "\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}
