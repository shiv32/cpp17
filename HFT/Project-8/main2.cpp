#include <iostream>
#include <vector>
#include <queue>

// upgraded Limit Order Book project using design patterns in a clean C++17 architecture.

// Order Model
enum class OrderType
{
    LIMIT,
    MARKET
};

struct Order
{
    int id;
    double price;
    int quantity;
    bool isBuy;
    OrderType type;
};

// C++ Data Structure Design
struct BuyCompare
{
    bool operator()(const Order &a, const Order &b)
    {
        return a.price < b.price; // max heap
    }
};

struct SellCompare
{
    bool operator()(const Order &a, const Order &b)
    {
        return a.price > b.price; // min heap
    }
};

std::priority_queue<Order, std::vector<Order>, BuyCompare> buyOrders;
std::priority_queue<Order, std::vector<Order>, SellCompare> sellOrders;

// Matching Engine (Core Logic)
void matchSell(Order &sell)
{
    while (!buyOrders.empty() && sell.quantity > 0)
    {
        Order topBuy = buyOrders.top();

        if (topBuy.price < sell.price)
            break;

        buyOrders.pop();

        int tradedQty = std::min(topBuy.quantity, sell.quantity);

        std::cout << "Sell Trade: " << tradedQty << " @ " << topBuy.price << "\n";

        topBuy.quantity -= tradedQty;
        sell.quantity -= tradedQty;

        if (topBuy.quantity > 0)
            buyOrders.push(topBuy);
    }

    if (sell.quantity > 0)
        sellOrders.push(sell);
}

void matchBuy(Order &buy)
{
    while (!sellOrders.empty() && buy.quantity > 0)
    {
        Order topSell = sellOrders.top();

        if (topSell.price > buy.price)
            break;

        sellOrders.pop();

        int tradedQty = std::min(topSell.quantity, buy.quantity);

        std::cout << "Buy Trade: " << tradedQty << " @ " << topSell.price << "\n";

        topSell.quantity -= tradedQty;
        buy.quantity -= tradedQty;

        if (topSell.quantity > 0)
            sellOrders.push(topSell);
    }

    if (buy.quantity > 0)
        buyOrders.push(buy);
}

// Strategy Pattern (Matching Logic)
class MatchingStrategy
{
public:
    virtual void match(Order &order) = 0;
    virtual ~MatchingStrategy() = default;
};

// Concrete Strategy (Price-Time)
class PriceTimeStrategy : public MatchingStrategy
{
public:
    void match(Order &order) override
    {
        std::cout << "Matching using Price-Time Strategy\n";
        // reuse your matching logic here

        if (order.isBuy)
            matchBuy(order);
        else
            matchSell(order);
    }
};

// Observer Pattern (Trade Events)
class Observer
{
public:
    virtual void onTrade(const std::string &tradeInfo) = 0;
};

// Concrete Observer
class Logger : public Observer
{
public:
    void onTrade(const std::string &tradeInfo) override
    {
        std::cout << "LOG: " << tradeInfo << "\n";
    }
};

// Subject (Engine)
class TradeNotifier
{
    std::vector<Observer *> observers;

public:
    void subscribe(Observer *obs)
    {
        observers.push_back(obs);
    }

    void notify(const std::string &msg)
    {
        for (auto *obs : observers)
            obs->onTrade(msg);
    }
};

// Singleton Pattern (Matching Engine)
class MatchingEngine
{
private:
    MatchingStrategy *strategy;
    TradeNotifier notifier;

    MatchingEngine()
    {
        strategy = new PriceTimeStrategy();
    }

public:
    static MatchingEngine &getInstance()
    {
        static MatchingEngine instance;
        return instance;
    }

    void addObserver(Observer *obs)
    {
        notifier.subscribe(obs);
    }

    void processOrder(Order order)
    {
        strategy->match(order);
        notifier.notify("Trade executed");
    }
};

// Command Pattern (Order Execution)
class Command
{
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

// Place Order Command
class PlaceOrderCommand : public Command
{
    Order order;

public:
    PlaceOrderCommand(Order o) : order(o) {}

    void execute() override
    {
        MatchingEngine::getInstance().processOrder(order);
    }
};

// Factory Pattern (Order Creation)
class OrderFactory
{
public:
    static Order createLimitOrder(int id, double price, int qty, bool isBuy)
    {
        return {id, price, qty, isBuy, OrderType::LIMIT};
    }
};

// Console UI (Menu-Based)
int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    Logger logger;
    auto &engine = MatchingEngine::getInstance();
    engine.addObserver(&logger);

    Order o1 = OrderFactory::createLimitOrder(1, 50, 100, true); // buy
    Order o2 = OrderFactory::createLimitOrder(2, 48, 80, false); // sell
    Order o3 = OrderFactory::createLimitOrder(3, 49, 50, false); // sell

    PlaceOrderCommand cmd1(o1);
    PlaceOrderCommand cmd2(o2);
    PlaceOrderCommand cmd3(o3);

    cmd1.execute();
    cmd2.execute();
    cmd3.execute();
}