//Main (Simulation)

#include "OrderBook.hpp"
#include <chrono>

long getTime()
{
    return std::chrono::system_clock::now().time_since_epoch().count();
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    OrderBook ob;

    ob.addOrder(Order(1, Side::BUY, 100.5, 10, getTime()));
    ob.addOrder(Order(2, Side::SELL, 99.5, 5, getTime()));
    ob.addOrder(Order(3, Side::SELL, 100.0, 10, getTime()));
    ob.addOrder(Order(4, Side::BUY, 101.0, 7, getTime()));

    return 0;
}