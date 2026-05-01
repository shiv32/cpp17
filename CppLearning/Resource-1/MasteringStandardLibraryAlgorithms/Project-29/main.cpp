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

namespace ma
{
    void example1()
    {
        int x = 4, y = 5;
        std::cout << "x is " << x << " and y is " << y << std::endl;
        std::cout << "Max is " << std::max(x, y) << std::endl;
        std::cout << "Min is " << std::min(x, y) << std::endl;

        // Using max() and min() on more than two values
        int x1 = 2, x2 = 9, x3 = 3, x4 = 12;
        std::cout << "Max of 4 elements is " << std::max({x1, x2, x3, x4}) << std::endl;
        std::cout << "Min of 4 elements is " << std::min({x1, x2, x3, x4}) << std::endl;

        // Using minmax()
        auto p2 = std::minmax({x1, x2, x3, x4});
        std::cout << "Minmax of 4 elements is <" << p2.first << "," << p2.second << ">" << std::endl;

        // Using minmax() + C++17 structured bindings
        auto [min1, max1] = std::minmax({x1, x2, x3, x4});
        std::cout << "Minmax of 4 elements is <" << min1 << "," << max1 << ">" << std::endl;

        // Using minmax_element() + C++17 structured bindings
        std::vector<int> vec{11, 33, 22};
        auto [min2, max2] = minmax_element(cbegin(vec), cend(vec));
        std::cout << "minmax_element() result: <" << *min2 << "," << *max2 << ">" << std::endl;

        auto maxValue = (std::max)(1, 2);
        std::cout << "maxValue : " << maxValue << std::endl;
    }

    void example2()
    {
        std::cout << std::clamp(-3, 1, 10) << std::endl;
        std::cout << std::clamp(3, 1, 10) << std::endl;
        std::cout << std::clamp(22, 1, 10) << std::endl;
    }

}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // ma::example1();
    ma::example2();

    return 0;
}