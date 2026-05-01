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

#include <numeric>
#include <vector>
#include <iostream>
#include <cmath>

namespace example
{
    int product(int num1, int num2)
    {
        return num1 * num2;
    }

    double arithmeticMean(const std::vector<int> &nums)
    {
        double sum = accumulate(cbegin(nums), cend(nums), 0);
        return sum / nums.size();
    }

    double geometricMean(const std::vector<int> &nums)
    {
        double mult = accumulate(cbegin(nums), cend(nums), 1, product);
        return pow(mult, 1.0 / nums.size()); // pow() needs <cmath>
    }

    double geometricMeanLambda(const std::vector<int> &nums)
    {
        double mult = accumulate(cbegin(nums), cend(nums), 1,
                                 [](int num1, int num2)
                                 { return num1 * num2; });

        return pow(mult, 1.0 / nums.size());
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::vector<int> myVector{2, 5, 6, 8};

    // auto result = example::arithmeticMean(myVector);
    // auto result = example::geometricMean(myVector);
    auto result = example::geometricMeanLambda(myVector);

    std::clog << result << std::endl;

    return 0;
}