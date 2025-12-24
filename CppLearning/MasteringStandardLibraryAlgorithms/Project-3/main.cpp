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
#include <functional>
#include <algorithm>

namespace example
{
    void func(int num, const std::string &str)
    {
        std::cout << "func(" << num << ", " << str << ")" << std::endl;
    }

    bool isEven(int num)
    {
        return num % 2 == 0;
    }

    void process(const std::vector<int> &vec, std::function<void(int)> f)
    {
        for (auto &i : vec)
        {
            f(i);
        }
    }

    void print(int num)
    {
        std::cout << num << "  ";
    }

    template <typename F>
    void processTemplate(const std::vector<int> &vec, F f)
    {
        for (auto &i : vec)
        {
            f(i);
        }
    }

    void demo_1()
    {
        // std::function<void(int, const std::string&)> f1 = func;
        //  auto f1 = func;
        //  f1(1, "test");

        std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};

        /*
        std::function<bool(int)> fcn = isEven;

        auto result = find_if(cbegin(vec), cend(vec), fcn);

        if (result != cend(vec))
        {
            std::cout << "First even number: " << *result << std::endl;
        }
        else
        {
            std::cout << "No even number found." << std::endl;
        }
        */

        // process(vec, print);
        processTemplate(vec, print);
        std::cout << std::endl;

        int sum = 0;
        process(vec, [&sum](int num)
                { sum += num; });
        // processTemplate(vec, [&sum](int num){ sum += num; });
        std::cout << "sum = " << sum << std::endl;
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    example::demo_1();

    return 0;
}