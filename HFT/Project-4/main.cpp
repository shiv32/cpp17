#include <iostream>
#include <vector>
#include <functional>
#include <random>
#include <chrono>
#include <thread>
#include <memory>
#include <iomanip>
#include <map>
#include <string>

// --- ENUMS ---
enum class Signal
{
    BUY,
    SELL,
    HOLD
};

// --- ORDER MODEL ---
struct Order
{
    int id;
    Signal signal;
    double price;
    int quantity;
    Order(int id_, Signal s, double p, int q)
        : id(id_), signal(s), price(p), quantity(q) {}
};

// --- LATENCY TRACKER ---
struct LatencyTracker
{
    static auto now()
    {
        return std::chrono::high_resolution_clock::now();
    }

    // C++ 20 auto allow in fun param
    // static long long durationNs(const auto &start, const auto &end)
    // {
    //     return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    // }

    template <typename T1, typename T2>
    static long long durationNs(const T1 &start, const T2 &end)
    {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    }
};

// --- STRATEGY INTERFACE ---
class IStrategy
{
public:
    virtual Signal onPriceUpdate(double price) = 0;
    virtual ~IStrategy() = default;
};

// --- STRATEGY 1: Mean Reversion ---
class SimpleMeanReversionStrategy : public IStrategy
{
    double avg = 0;
    int count = 0;

public:
    Signal onPriceUpdate(double price) override
    {
        avg = (avg * count + price) / (count + 1);
        ++count;
        if (price < avg * 0.98)
            return Signal::BUY;
        if (price > avg * 1.02)
            return Signal::SELL;
        return Signal::HOLD;
    }
};

// --- STRATEGY 2: Momentum ---
class MomentumStrategy : public IStrategy
{
    double lastPrice = 0;

public:
    Signal onPriceUpdate(double price) override
    {
        if (lastPrice == 0)
        {
            lastPrice = price;
            return Signal::HOLD;
        }
        Signal s = (price > lastPrice) ? Signal::BUY : Signal::SELL;
        lastPrice = price;
        return s;
    }
};

// --- STRATEGY FACTORY ---
class StrategyFactory
{
public:
    static std::shared_ptr<IStrategy> create(const std::string &type)
    {
        if (type == "mean")
            return std::make_shared<SimpleMeanReversionStrategy>();
        else if (type == "momentum")
            return std::make_shared<MomentumStrategy>();
        else
            throw std::runtime_error("Unknown strategy: " + type);
    }
};

// --- ORDER MANAGER ---
class OrderManager
{
    std::vector<Order> orders;
    int nextId = 1;

public:
    void sendOrder(const Order &order)
    {
        orders.push_back(order);
        std::string action = (order.signal == Signal::BUY) ? "BUY" : "SELL";
        std::cout << "[ORDER] #" << order.id << ": " << action
                  << " Qty=" << order.quantity << " @ " << order.price << "\n";
    }

    void listOrders() const
    {
        std::cout << "\n[ORDER BOOK]\n";
        for (const auto &o : orders)
        {
            std::string action = (o.signal == Signal::BUY) ? "BUY" : "SELL";
            std::cout << "#" << o.id << ": " << action
                      << " " << o.quantity << " @ " << o.price << "\n";
        }
    }
};

// --- COMMAND INTERFACE ---
class ICommand
{
public:
    virtual void execute() = 0;
    virtual ~ICommand() = default;
};

// --- SEND ORDER COMMAND ---
class SendOrderCommand : public ICommand
{
    Order order;
    OrderManager &manager;

public:
    SendOrderCommand(Order o, OrderManager &m)
        : order(std::move(o)), manager(m) {}

    void execute() override
    {
        manager.sendOrder(order);
    }
};

// --- COMMAND FACTORY ---
class CommandFactory
{
    OrderManager &manager;

public:
    CommandFactory(OrderManager &mgr) : manager(mgr) {}
    std::unique_ptr<ICommand> create(Signal signal, double price)
    {
        static int orderId = 1000;
        int qty = 10;
        Order order(orderId++, signal, price, qty);
        return std::make_unique<SendOrderCommand>(order, manager);
    }
};

// --- TRADER ---
class Trader
{
    std::shared_ptr<IStrategy> strategy;
    CommandFactory &factory;

public:
    Trader(std::shared_ptr<IStrategy> strat, CommandFactory &f)
        : strategy(std::move(strat)), factory(f) {}

    void onPrice(double price)
    {
        auto start = LatencyTracker::now();
        Signal sig = strategy->onPriceUpdate(price);
        if (sig != Signal::HOLD)
        {
            auto cmd = factory.create(sig, price);
            cmd->execute();
        }
        auto end = LatencyTracker::now();
        std::cout << "[LATENCY] " << LatencyTracker::durationNs(start, end) << " ns\n";
    }
};

// --- MARKET DATA FEED ---
class MarketDataFeed
{
    std::vector<std::function<void(double)>> subscribers;
    std::default_random_engine gen;
    std::normal_distribution<double> dist;

public:
    MarketDataFeed() : dist(100.0, 1.5) {}

    void subscribe(const std::function<void(double)> &callback)
    {
        subscribers.push_back(callback);
    }

    void run(int ticks = 10)
    {
        for (int i = 0; i < ticks; ++i)
        {
            double price = dist(gen);
            std::cout << "\n[PRICE] Tick " << i + 1 << ": " << std::fixed << std::setprecision(2) << price << "\n";
            for (auto &cb : subscribers)
            {
                cb(price);
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }
};

// --- MAIN ---
int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::string strategyType;
    std::cout << "Enter strategy (mean/momentum): ";
    std::cin >> strategyType;

    try
    {
        auto strategy = StrategyFactory::create(strategyType);
        OrderManager orderManager;
        CommandFactory commandFactory(orderManager);
        Trader trader(strategy, commandFactory);
        MarketDataFeed feed;

        feed.subscribe([&trader](double price)
                       { trader.onPrice(price); });

        feed.run(15);
        orderManager.listOrders();
    }
    catch (const std::exception &ex)
    {
        std::cerr << "Error: " << ex.what() << '\n';
    }

    return 0;
}
