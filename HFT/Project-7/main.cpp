#include <iostream>
#include <queue>

namespace test
{
    // Basic Example (Max Heap - default)
    // By default, it is a Max Heap (largest element first)
    void example_1()
    {
        std::priority_queue<int> pq;

        pq.push(10);
        pq.push(5);
        pq.push(20);
        pq.push(15);

        while (!pq.empty())
        {
            std::cout << pq.top() << " ";
            pq.pop();
        }

        std::cout << "\n";
    }

    // Min Heap Example
    void example_2()
    {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

        pq.push(10);
        pq.push(5);
        pq.push(20);
        pq.push(15);

        while (!pq.empty())
        {
            std::cout << pq.top() << " ";
            pq.pop();
        }

        std::cout << "\n";
    }

    struct Order
    {
        int price;
        int quantity;

        // Max heap based on price
        bool operator<(const Order &other) const
        {
            return price < other.price;
        }
    };

    // Custom Object Example (Important)
    void example_3()
    {
        std::priority_queue<Order> buyOrders;

        buyOrders.push({100, 10});
        buyOrders.push({105, 5});
        buyOrders.push({102, 20});

        while (!buyOrders.empty())
        {
            Order o = buyOrders.top();

            std::cout << "Price: " << o.price
                      << " Qty: " << o.quantity << std::endl;

            buyOrders.pop();
        }
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    test::example_1();
    test::example_2();
    test::example_3();
}