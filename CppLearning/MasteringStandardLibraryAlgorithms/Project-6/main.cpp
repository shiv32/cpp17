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

namespace countif
{
    void example1()
    {
        std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
        int value = 3;
        int cnt = std::count_if(cbegin(vec), cend(vec), [value](int i){ return i > value; });
        std::cout << "Found " << cnt << " values > " << value << std::endl;
    }

    void example2()
    {
        std::vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        int value = 3;
        int cntLambdaCalled = 0;
        int cnt = count_if(cbegin(vec), cend(vec), [value, &cntLambdaCalled](int i){ ++cntLambdaCalled; return i > value; });
        std::cout << "The lambda expression was called " << cntLambdaCalled << " times." << std::endl;
        std::cout << "Found " << cnt << " values > " << value << std::endl;
    }
}

namespace generate
{
    void example1()
    {
        std::vector<int> vec(10);
        int value = 1;
        
        // std::generate(begin(vec), end(vec), [&value]{ value *= 2; return value; });
         std::generate(begin(vec), end(vec), [value]() mutable { value *= 2; return value; });//not need &value

        for (const auto& i : vec) 
        {
            std::cout << i << " ";
        }

        std::cout<<std::endl;
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // countif::example1();
    // countif::example2();

    generate::example1();

    return 0;
}