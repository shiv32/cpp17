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

namespace negators
{
    std::vector<int> myVector{200, 5, 700, 9};

    bool perfectScore(int num)
    {
        return (num >= 100);
    }

    void example1()
    {
        auto endIter = end(myVector);

        auto it = find_if(std::begin(myVector), endIter, std::not_fn(perfectScore));

        if (it == endIter)
        {
            std::cout << "All perfect scores" << std::endl;
        }
        else
        {
            std::cout << "Found a \"less-than-perfect\" score of " << *it << std::endl;
        }
    }

    void example2()
    {
        auto endIter = end(myVector);

        auto it = find_if(begin(myVector), endIter, [](int i){ return i < 100; });

        if (it == endIter)
        {
            std::cout << "All perfect scores" << std::endl;
        }
        else
        {
            std::cout << "Found a \"less-than-perfect\" score of " << *it << std::endl;
        }
    }

    void example3()
    {
        auto endIter = end(myVector);

        std::function<bool(int)> f = perfectScore;

        auto it = find_if(begin(myVector), endIter, std::not1(f)); // deprecated not1

        if (it == endIter)
        {
            std::cout << "All perfect scores" << std::endl;
        }
        else
        {
            std::cout << "Found a \"less-than-perfect\" score of " << *it << std::endl;
        }
    }

    class PerfectScore : public std::unary_function<int, bool> // deprecated unary_function
    {
    public:
        result_type operator()(const argument_type &score) const
        {
            return score >= 100;
        }
    };

    void example4()
    {
        auto endIter = end(myVector);

        std::function<bool(int)> f = perfectScore;

        auto it = find_if(begin(myVector), endIter, std::not1(PerfectScore())); // deprecated not1

        if (it == endIter)
        {
            std::cout << "All perfect scores" << std::endl;
        }
        else
        {
            std::cout << "Found a \"less-than-perfect\" score of " << *it << std::endl;
        }
    }

}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    negators::example1();
    negators::example2();
    negators::example3();
    negators::example4();

    return 0;
}