//Order Book (Core Logic)

#pragma once
#include "Order.hpp"
#include <queue>
#include <iostream>

// BUY: highest price first
struct BuyComparator
{
    bool operator()(const Order &a, const Order &b)
    {
        if (a.price == b.price)
            return a.timestamp > b.timestamp;
        return a.price < b.price;
    }
};

// SELL: lowest price first
struct SellComparator
{
    bool operator()(const Order &a, const Order &b)
    {
        if (a.price == b.price)
            return a.timestamp > b.timestamp;
        return a.price > b.price;
    }
};

class OrderBook
{
private:
    std::priority_queue<Order, std::vector<Order>, BuyComparator> buyOrders;
    std::priority_queue<Order, std::vector<Order>, SellComparator> sellOrders;

public:
    void addOrder(Order order)
    {
        if (order.side == Side::BUY)
        {
            matchBuy(order);
        }
        else
        {
            matchSell(order);
        }
    }

private:
    void matchBuy(Order &buy)
    {
        while (!sellOrders.empty() && buy.quantity > 0)
        {
            Order topSell = sellOrders.top();

            if (topSell.price > buy.price)
                break;

            sellOrders.pop();

            int tradedQty = std::min(buy.quantity, topSell.quantity);
            buy.quantity -= tradedQty;
            topSell.quantity -= tradedQty;

            std::cout << "TRADE: BUY " << tradedQty
                      << " @ " << topSell.price << "\n";

            if (topSell.quantity > 0)
                sellOrders.push(topSell);
        }

        if (buy.quantity > 0)
            buyOrders.push(buy);
    }

    void matchSell(Order &sell)
    {
        while (!buyOrders.empty() && sell.quantity > 0)
        {
            Order topBuy = buyOrders.top();

            if (topBuy.price < sell.price)
                break;

            buyOrders.pop();

            int tradedQty = std::min(sell.quantity, topBuy.quantity);
            sell.quantity -= tradedQty;
            topBuy.quantity -= tradedQty;

            std::cout << "TRADE: SELL " << tradedQty
                      << " @ " << topBuy.price << "\n";

            if (topBuy.quantity > 0)
                buyOrders.push(topBuy);
        }

        if (sell.quantity > 0)
            sellOrders.push(sell);
    }
};