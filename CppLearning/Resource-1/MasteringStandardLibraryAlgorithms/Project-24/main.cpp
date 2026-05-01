/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 *
 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <algorithm>
#include <functional>
#include <map>

namespace foreach
{
    // Function template to populate a container of ints.
    // The container must support push_back().
    template <typename Container>
    void populateContainer(Container &cont)
    {
        int num;
        while (true)
        {
            std::cout << "Enter a number (0 to quit): ";
            std::cin >> num;

            if (num == 0)
            {
                break;
            }

            cont.push_back(num);
        }
    }

    void example1()
    {
        std::map<int, int> myMap = {{4, 40}, {5, 50}, {6, 60}};

        for_each(cbegin(myMap), cend(myMap),

                 [](const auto &p)
                 { std::cout << p.first << "->" << p.second << std::endl; }

        );
    }

    void example2()
    {
        std::vector<int> myVector;

        populateContainer(myVector);

        int sum = 0;
        int product = 1;

        for_each(cbegin(myVector), cend(myVector),

                 [&sum, &product](int i)
                 {
                     sum += i;
                     product *= i;
                 }

        );

        std::cout << "The sum is " << sum << std::endl;
        std::cout << "The product is " << product << std::endl;
    }

    class SumAndProduct // functor
    {
    public:
        void operator()(int value);
        int getSum() const { return mSum; }
        int getProduct() const { return mProduct; }

    private:
        int mSum = 0;
        int mProduct = 1;
    };

    void SumAndProduct::operator()(int value)
    {
        mSum += value;
        mProduct *= value;
    }

    void example3()
    {
        std::vector<int> myVector;

        populateContainer(myVector);

        SumAndProduct func;

        func = for_each(cbegin(myVector), cend(myVector), func);

        std::cout << "The sum is " << func.getSum() << std::endl;
        std::cout << "The product is " << func.getProduct() << std::endl;
    }
}

namespace foreachn
{
    void example1()
    {
        std::map<int, int> myMap = {{4, 40}, {5, 50}, {6, 60}};

        for_each_n(cbegin(myMap), 2,

                   [](const auto &p)
                   {
                       std::cout << p.first << "->" << p.second << std::endl;
                   }
        );
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // foreach::example1();
    // foreach::example2();
    // foreach::example3();

    foreachn::example1();

    return 0;
}