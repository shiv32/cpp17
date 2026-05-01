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
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cmath>
#include <queue>

namespace AFO
{
    void example1()
    {
        std::plus<int> myPlus;
        int res = myPlus(4, 5);
        std::cout << res << std::endl;
    }

    double geometricMean(const std::vector<int> &nums)
    {
        double mult = accumulate(cbegin(nums), cend(nums), 1, std::multiplies<int>());
        return pow(mult, 1.0 / nums.size());
    }

    double geometricMeanTransparent(const std::vector<int> &nums)
    {
        double mult = accumulate(cbegin(nums), cend(nums), 1, std::multiplies<>());
        return pow(mult, 1.0 / nums.size());
    }

    void example2(const std::vector<int> &nums)
    {
        double result = accumulate(cbegin(nums), cend(nums), 1.1, std::multiplies<>());
        std::cout << result << std::endl;
    }

    void example3(const std::vector<int> &nums)
    {
        double result = accumulate(cbegin(nums), cend(nums), 1.1, std::multiplies<int>());
        std::cout << result << std::endl;
    }
}

namespace CFO
{
    void example1()
    {
        std::priority_queue<int> myQueue;

        myQueue.push(3);
        myQueue.push(4);
        myQueue.push(2);
        myQueue.push(1);

        while (!myQueue.empty())
        {
            std::cout << myQueue.top() << " ";
            myQueue.pop();
        }

        std::cout << std::endl;
    }

    void example2()
    {
        // template <class T, class Container = vector<T>, class Compare = less<T>>;
        std::priority_queue<int, std::vector<int>, std::greater<>> myQueue;

        myQueue.push(3);
        myQueue.push(4);
        myQueue.push(2);
        myQueue.push(1);

        while (!myQueue.empty())
        {
            std::cout << myQueue.top() << " ";
            myQueue.pop();
        }

        std::cout << std::endl;
    }
}

namespace LFO
{
    bool allTrue(const std::vector<bool> &flags)
    {
        return accumulate(begin(flags), end(flags), true, std::logical_and<>());
    }

    bool anyTrue(const std::vector<bool> &flags)
    {
        return accumulate(begin(flags), end(flags), false, std::logical_or<>());
    }
}

namespace BFO
{
    void example1()
    {
        std::vector<int> flags{1, 2, 4};
        int result = std::accumulate(flags.begin(), flags.end(), 0, std::bit_or<int>{});
        std::cout << result << std::endl;
    }

    void example2()
    {
        std::vector<int> data{15, 7, 3, 1};
        int mask = 3;

        std::transform(
            data.begin(),
            data.end(),
            data.begin(),
            [mask](int v)
            {
                return std::bit_and<int>{}(v, mask);
            });

        for (int v : data)
            std::cout << v << ' ';

        std::cout << std::endl;
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // AFO::example1();

    // std::vector<int> nums{1, 2, 3};
    //  std::cout << AFO::geometricMean(nums) << std::endl;
    //  std::cout << AFO::geometricMeanTransparent(nums) << std::endl;

    // AFO::example2(nums);
    // AFO::example3(nums);

    //------------------
    // CFO::example1();
    // CFO::example2();

    //-----------------
    // std::vector<bool> flag1{true, true, true};
    // std::vector<bool> flag2{true, false, true};

    // std::cout << LFO::allTrue(flag1) << std::endl;
    // std::cout << LFO::allTrue(flag2) << std::endl;

    // std::cout << LFO::anyTrue(flag1) << std::endl;
    // std::cout << LFO::anyTrue(flag2) << std::endl;

    //------------
    // BFO::example1();
    BFO::example2();

    return 0;
}