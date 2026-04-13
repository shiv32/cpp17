#include <iostream>
#include <queue>
#include <vector>
#include <functional>

enum class Side
{
    BUY,
    SELL
};

struct Order
{
    int id;
    Side side;
    int price;
    int qty;
};

struct Trade
{
    int price;
    int qty;
};

struct CompareBuy
{
    bool operator()(const Order &a, const Order &b)
    {
        return a.price < b.price; // max heap
    }
};

struct CompareSell
{
    bool operator()(const Order &a, const Order &b)
    {
        return a.price > b.price; // min heap
    }
};

class OrderBook
{
public:
    std::priority_queue<Order, std::vector<Order>, CompareBuy> buys;
    std::priority_queue<Order, std::vector<Order>, CompareSell> sells;
};

class MatchingEngine
{
public:
    int lastPrice = 0;
    int totalVolume = 0;

    std::function<void(const Trade &)> onTrade; // callback

    void process(OrderBook &book, Order order)
    {
        if (order.side == Side::BUY)
        {
            matchBuy(book, order);
            if (order.qty > 0)
                book.buys.push(order);
        }
        else
        {
            matchSell(book, order);
            if (order.qty > 0)
                book.sells.push(order);
        }
    }

private:
    void matchBuy(OrderBook &book, Order &buy)
    {
        while (!book.sells.empty() && buy.qty > 0)
        {
            auto top = book.sells.top();
            if (top.price > buy.price)
                break;

            book.sells.pop();
            int traded = std::min(buy.qty, top.qty);

            buy.qty -= traded;
            top.qty -= traded;

            Trade t{top.price, traded};
            publish(t);

            if (top.qty > 0)
                book.sells.push(top);
        }
    }

    void matchSell(OrderBook &book, Order &sell)
    {
        while (!book.buys.empty() && sell.qty > 0)
        {
            auto top = book.buys.top();
            if (top.price < sell.price)
                break;

            book.buys.pop();
            int traded = std::min(sell.qty, top.qty);

            sell.qty -= traded;
            top.qty -= traded;

            Trade t{top.price, traded};
            publish(t);

            if (top.qty > 0)
                book.buys.push(top);
        }
    }

    void publish(const Trade &t)
    {
        lastPrice = t.price;
        totalVolume += t.qty;

        if (onTrade)
            onTrade(t);
    }
};

class HFTAlgo
{
public:
    int id = 1;

    // reacts to market trades
    void onMarketData(const Trade &t, MatchingEngine &engine, OrderBook &book)
    {
        // simple strategy: if price < 100 → buy, else sell
        Order o;
        o.id = id++;
        o.qty = 10;

        if (t.price < 100)
        {
            o.side = Side::BUY;
            o.price = t.price;
        }
        else
        {
            o.side = Side::SELL;
            o.price = t.price;
        }

        engine.process(book, o);
    }
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    OrderBook book;
    MatchingEngine engine;
    HFTAlgo hft;

    // connect market data to HFT
    engine.onTrade = [&](const Trade &t)
    {
        std::cout << "Trade: " << t.qty << " @ " << t.price << "\n";
        hft.onMarketData(t, engine, book);
    };

    // initial liquidity
    engine.process(book, {1, Side::SELL, 100, 50});
    engine.process(book, {2, Side::BUY, 99, 50});

    // trigger first trade
    engine.process(book, {3, Side::BUY, 100, 10});

    // trigger second trade
    engine.process(book, {4, Side::SELL, 90, 20});

    return 0;
}