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

namespace mcopy
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
        std::vector<int> vec1, vec2;

        populateContainer(vec1);

        vec2.resize(size(vec1));

        copy(cbegin(vec1), cend(vec1), begin(vec2));

        for (const auto &i : vec2)
        {
            std::cout << i << " ";
        }
    }

    void example2()
    {

        std::vector<int> vec1, vec2;

        populateContainer(vec1);

        vec2.resize(size(vec1));

        copy_backward(cbegin(vec1), cend(vec1), end(vec2));

        for (const auto &i : vec2)
        {
            std::cout << i << " ";
        }
    }

    void example3()
    {
        std::vector<int> vec1, vec2;

        populateContainer(vec1);

        vec2.resize(size(vec1));

        auto endIterator = copy_if(cbegin(vec1), cend(vec1), begin(vec2), [](int i)
                                   { return i % 2 == 0; });

        vec2.erase(endIterator, end(vec2));

        for (const auto &i : vec2)
        {
            std::cout << i << " ";
        }
    }

    void example4()
    {
        std::vector<int> vec1, vec2;

        populateContainer(vec1);

        size_t cnt = 0;
        std::cout << "Enter number of elements you want to copy: ";
        std::cin >> cnt;

        cnt = std::min(cnt, size(vec1));

        vec2.resize(cnt);

        copy_n(cbegin(vec1), cnt, begin(vec2));

        for (const auto &i : vec2)
        {
            std::cout << i << " ";
        }
    }

}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // mcopy::example1();
    // mcopy::example2();
    // mcopy::example3();
    mcopy::example4();

    return 0;
}