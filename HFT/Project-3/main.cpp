#include <iostream>
#include <vector>
#include <deque>
#include <memory>
#include <functional>
#include <random>
#include <chrono>
#include <thread>

// ---------------- Observer Pattern ----------------
class MarketObserver
{
public:
    virtual void onPriceUpdate(double price) = 0;
    virtual ~MarketObserver() = default;
};

// ---------------- Market Data Feed ----------------
class MarketDataFeed
{
    std::vector<MarketObserver *> observers;
    std::default_random_engine rng;
    std::uniform_real_distribution<double> dist;

public:
    MarketDataFeed() : dist(100.0, 110.0) {}

    void subscribe(MarketObserver *obs)
    {
        observers.push_back(obs);
    }

    void runSimulation(int ticks = 20)
    {
        for (int i = 0; i < ticks; ++i)
        {
            double price = dist(rng);
            std::cout << "[Tick " << i + 1 << "] Price: " << price << "\n";
            for (auto *obs : observers)
            {
                obs->onPriceUpdate(price);
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }
    }
};

// ---------------- Strategy Pattern ----------------
class TradingStrategy
{
public:
    virtual std::string generateSignal(double price) = 0;
    virtual ~TradingStrategy() = default;
};

class MovingAverageStrategy : public TradingStrategy
{
    std::deque<double> window;
    size_t period;

public:
    MovingAverageStrategy(size_t p) : period(p) {}

    std::string generateSignal(double price) override
    {
        window.push_back(price);
        if (window.size() > period)
            window.pop_front();

        if (window.size() < period)
            return "HOLD";

        double avg = 0.0;
        for (double p : window)
            avg += p;
        avg /= period;

        if (price > avg + 0.5)
            return "SELL";
        if (price < avg - 0.5)
            return "BUY";
        return "HOLD";
    }
};

// ---------------- Order Executor ----------------
class OrderExecutor
{
public:
    void execute(const std::string &signal, double price)
    {
        if (signal == "BUY")
        {
            std::cout << "[Order] BUY at " << price << "\n";
        }
        else if (signal == "SELL")
        {
            std::cout << "[Order] SELL at " << price << "\n";
        }
        else
        {
            std::cout << "[Order] HOLD\n";
        }
    }
};

// ---------------- Trader (combines all) ----------------
class Trader : public MarketObserver
{
    std::unique_ptr<TradingStrategy> strategy;
    OrderExecutor executor;

public:
    Trader(std::unique_ptr<TradingStrategy> strat) : strategy(std::move(strat)) {}

    void onPriceUpdate(double price) override
    {
        std::string signal = strategy->generateSignal(price);
        executor.execute(signal, price);
    }
};

// ---------------- Factory Pattern ----------------
class StrategyFactory
{
public:
    static std::unique_ptr<TradingStrategy> createStrategy(const std::string &type)
    {
        if (type == "MA")
        {
            return std::make_unique<MovingAverageStrategy>(3);
        }
        // Future: add more strategies
        else
        {
            throw std::invalid_argument("Unknown strategy type");
        }
    }
};

// ---------------- Main ----------------
int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    MarketDataFeed market;

    auto strategy = StrategyFactory::createStrategy("MA");
    Trader trader(std::move(strategy));

    market.subscribe(&trader);
    market.runSimulation();

    return 0;
}
