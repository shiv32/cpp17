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

namespace replace
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
        std::vector<int> vec;
        
        populateContainer(vec);

        replace_if(begin(vec), end(vec), [](int i){ return i % 2 != 0; }, 0);

        for (const auto& i : vec) { std::cout << i << " "; }
    }

}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    replace::example1();

    return 0;
}