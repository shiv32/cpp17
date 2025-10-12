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

int main(int argc, char *argv[])
{

    Price<Usd> usd(100);
    Price<Euro> euro(90);

    // The following line would cause a compile-time error
    // source>:113:27: error: no match for 'operator+' (operand types are 'Price<Usd>' and 'Price<Euro>')
    // Price<Usd> total = usd + euro;

    Price<Usd> total = usd + Price<Usd>(50); // Correct usage

    std::cout << total << std::endl; // Outputs: 150 USD

    return 0;
}