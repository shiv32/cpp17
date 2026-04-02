//Order Model

#pragma once
#include <string>

enum class Side
{
    BUY,
    SELL
};

struct Order
{
    int id;
    Side side;
    double price;
    int quantity;
    long timestamp;

    Order(int i, Side s, double p, int q, long t)
        : id(i), side(s), price(p), quantity(q), timestamp(t) {}
};