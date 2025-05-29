#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <memory>

// === Generic Observer Pattern ===

template <typename T>
class Observer
{
public:
    virtual void onNotify(const T &data) = 0;
};

template <typename T>
class Subject
{
    std::vector<Observer<T> *> observers;

public:
    void addObserver(Observer<T> *obs)
    {
        observers.push_back(obs);
    }

    void removeObserver(Observer<T> *obs)
    {
        observers.erase(std::remove(observers.begin(), observers.end(), obs), observers.end());
    }

    void notify(const T &data)
    {
        for (auto *obs : observers)
            obs->onNotify(data);
    }
};

// === Stock Event Structure ===

struct StockEvent
{
    std::string ticker;
    double price;
};

// === Investor ===

class Investor : public Observer<StockEvent>
{
    std::string name;

public:
    Investor(const std::string &n) : name(n) {}
    void onNotify(const StockEvent &event) override
    {
        std::cout << "[Investor: " << name << "] " << event.ticker
                  << " price: $" << event.price << "\n";
    }
};

// === Stock (Subject) ===

class Stock : public Subject<StockEvent>
{
    std::string ticker;
    double price;

public:
    Stock(std::string name, double initialPrice)
        : ticker(std::move(name)), price(initialPrice) {}

    void fluctuate()
    {
        static std::mt19937 gen{std::random_device{}()};
        std::uniform_real_distribution<> dist(-2.0, 2.0);
        price += dist(gen);
        if (price < 1.0)
            price = 1.0;

        notify(StockEvent{ticker, price});
    }

    double getPrice() const { return price; }
    const std::string &getName() const { return ticker; }
};

// === Command Pattern ===

template <typename T>
class Command
{
public:
    virtual void execute(const T &target) = 0;
};

class BuyCommand : public Command<Stock>
{
public:
    void execute(const Stock &stock) override
    {
        std::cout << "[Trade] Buying " << stock.getName() << " at $" << stock.getPrice() << "\n";
    }
};

class SellCommand : public Command<Stock>
{
public:
    void execute(const Stock &stock) override
    {
        std::cout << "[Trade] Selling " << stock.getName() << " at $" << stock.getPrice() << "\n";
    }
};

// === Main Simulation ===

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    Stock apple("AAPL", 150.0);
    Stock tesla("TSLA", 700.0);

    Investor alice("Alice");
    Investor bob("Bob");

    apple.addObserver(&alice);
    tesla.addObserver(&bob);
    tesla.addObserver(&alice);

    BuyCommand buy;
    SellCommand sell;

    for (int i = 0; i < 3; ++i)
    {
        std::cout << "\n[Market Tick " << (i + 1) << "]\n";
        apple.fluctuate();
        tesla.fluctuate();
    }

    std::cout << "\n[Executing Trades]\n";
    buy.execute(apple);
    sell.execute(tesla);

    return 0;
}
