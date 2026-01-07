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
#include <random>

namespace sample
{
    void example1()
    {
        std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        const size_t numberOfSamples = 5;
        std::vector<int> samples(numberOfSamples);

        std::random_device seeder;
        const auto seed = seeder.entropy() ? seeder() : time(nullptr);
        std::default_random_engine engine(static_cast<std::default_random_engine::result_type>(seed));

        for (int i = 0; i < 6; ++i)
        {
            std::sample(cbegin(vec), cend(vec), begin(samples), numberOfSamples, engine);

            for (const auto &sample : samples)
            {
                std::cout << sample << " ";
            }

            std::cout << std::endl;
        }
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    sample::example1();

    return 0;
}