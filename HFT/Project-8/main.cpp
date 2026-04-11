#include <iostream>
#include <queue>
#include <vector>

// Basic unit in trading
// Order
struct Order
{
    int id;
    double price;
    int quantity;
    bool isBuy; // true = buy, false = sell
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

        std::cout << "Trade: "
                  << tradedQty << " @ " << topBuy.price << "\n";

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

        std::cout << "Trade: "
                  << tradedQty << " @ " << topSell.price << "\n";

        topSell.quantity -= tradedQty;
        buy.quantity -= tradedQty;

        if (topSell.quantity > 0)
            sellOrders.push(topSell);
    }

    if (buy.quantity > 0)
        buyOrders.push(buy);
}

// Order Entry API
void addOrder(Order order)
{
    if (order.isBuy)
        matchBuy(order);
    else
        matchSell(order);
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    addOrder({1, 50, 100, true}); // Buy
    addOrder({2, 48, 80, false}); // Sell
    addOrder({3, 49, 50, false}); // Sell
}