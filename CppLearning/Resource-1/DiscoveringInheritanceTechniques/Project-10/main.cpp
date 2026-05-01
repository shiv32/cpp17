/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Referring to Parent Names part 1
 * @version 0.1
 * @date 2024-08-26
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>
#include <memory>
#include "MyWeatherPrediction.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    auto mwp = std::make_unique<MyWeatherPrediction>();

    std::cout << mwp->getTemperature()<< std::endl;

    return 0;
}