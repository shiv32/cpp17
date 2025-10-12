#include <iostream>

// Using templates for currency definition

struct Usd
{
    static const std::string &name()
    {
        static std::string name = "USD";
        return name;
    }
};

struct Euro
{
    static const std::string &name()
    {
        static std::string name = "EUR";
        return name;
    }
};

template <typename Currency>
class Price
{
public:
    Price(int64_t amount) : _amount(amount)
    {
    }

    int64_t count() const
    {
        return _amount;
    }

private:
    int64_t _amount;
};

template <typename Currency>
std::ostream &operator<<(std::ostream &os, const Price<Currency> &price)
{
    os << price.count() << " " << Currency::name();
    return os;
}

template <typename Currency>
Price<Currency> operator+(const Price<Currency> &lhs, const Price<Currency> &rhs)
{
    return Price<Currency>(lhs.count() + rhs.count());
}

template <typename Currency>
Price<Currency> operator-(const Price<Currency> &lhs, const Price<Currency> &rhs)
{
    return Price<Currency>(lhs.count() - rhs.count());
}

// User can define other arithmetic operations as needed

// Defining assets

template <typename TickerT>
class Asset;

struct Apple
{
    static const std::string &name()
    {
        static std::string name = "AAPL";
        return name;
    }

    static const std::string &exchange()
    {
        static std::string exchange = "NASDAQ";
        return exchange;
    }

    using Asset = class Asset<Apple>;
    using Currency = Usd;
};

struct Mercedes
{
    static const std::string &name()
    {
        static std::string name = "MGB";
        return name;
    }

    static const std::string &exchange()
    {
        static std::string exchange = "FRA";
        return exchange;
    }

    using Asset = class Asset<Mercedes>;
    using Currency = Euro;
};

template <typename TickerT>
class Asset
{
public:
    using Ticker = TickerT;
    using Currency = typename Ticker::Currency;

    Asset(int64_t amount, Price<Currency> price)
        : _amount(amount), _price(price)
    {
    }

    auto amount() const { return _amount; }
    auto price() const { return _price; }

private:
    int64_t _amount;
    Price<Currency> _price;
};

template <typename TickerT>
std::ostream &operator<<(std::ostream &os, const Asset<TickerT> &asset)
{
    os << TickerT::name() << ", amount: " << asset.amount() << ", price: " << asset.price();

    return os;
}

int main(int argc, char *argv[])
{

    // use the defined templates to manage assets and prices.
    Price<Usd> usd_price(100);
    usd_price = usd_price + Price<Usd>(1);

    std::cout << usd_price << std::endl; // Outputs: 101 USD

    Asset<Apple> apple{10, Price<Usd>(100)};
    Asset<Mercedes> mercedes{5, Price<Euro>(100)};

    std::cout << apple << std::endl;    // Outputs: AAPL, amount: 10, price: 100 USD
    std::cout << mercedes << std::endl; // Outputs: MGB, amount: 5, price: 100 EUR

    return 0;
}