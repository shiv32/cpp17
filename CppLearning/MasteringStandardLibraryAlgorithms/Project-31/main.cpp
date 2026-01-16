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
#include <execution> //inner_product

namespace npa
{
    void example1()
    {
        std::vector<int> v1{1, 2, 3, 4};
        std::vector<int> v2{9, 8, 7, 6};

        //(1*9)+(2*8)+(3*7)+(4*6)
        std::cout << inner_product(cbegin(v1), cend(v1), cbegin(v2), 0) << std::endl;
    }

    void example2()
    {
        std::vector<int> vec(10);

        iota(begin(vec), end(vec), 5);

        for (auto &i : vec)
        {
            std::cout << i << " ";
        }

        std::cout << std::endl;
    }

    void example3()
    {
        auto g = std::gcd(3, 18); // g = 3
        std::cout << g << std::endl;

        auto l = std::lcm(3, 18); // l = 18
        std::cout << l << std::endl;
    }

    void example4()
    {
        std::vector<int> vec{8, 4, 2, 9};

        // does not support parallel execution
        double result1 = std::accumulate(cbegin(vec), cend(vec), 0.0);
        std::cout << result1 << std::endl;

        // execute it in parallel
        double result2 = std::reduce(std::execution::par_unseq, cbegin(vec), cend(vec));
        std::cout << result2 << std::endl;
    }

    void example5()
    {
        std::vector<int> v1{1, 2, 3, 4};
        std::vector<int> v2{9, 8, 7, 6};

        //(1*9)+(2*8)+(3*7)+(4*6) //does not support parallel execution
        std::cout << inner_product(cbegin(v1), cend(v1), cbegin(v2), 0) << std::endl;

        //(1*9)+(2*8)+(3*7)+(4*6) //execute it in parallel
        std::cout << transform_reduce(std::execution::par_unseq, cbegin(v1), cend(v1), cbegin(v2), 0) << std::endl;
    }

}

namespace sa
{
    void example1()
    {
        std::vector<int> v{1, 2, 3, 4};
        std::vector<int> out(v.size());

        // Scan Algorithm, partial_sum cannot be parallelized.
        std::partial_sum(v.begin(), v.end(), out.begin());

        for (int x : out)
            std::cout << x << " ";

        std::cout << std::endl;
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // npa::example1();
    // npa::example2();
    // npa::example3();
    // npa::example4();
    // npa::example5();

    sa::example1();

    return 0;
}