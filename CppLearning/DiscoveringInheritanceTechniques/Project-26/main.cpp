/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief The Base Class Method Is private or protected
 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
//#include "MilesEstimator.hpp"
#include "EfficientCarMilesEstimator.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    MilesEstimator myMilesEstimator;
    myMilesEstimator.setGallonsLeft(2);
    std::cout << "Normal estimator can go " << myMilesEstimator.getMilesLeft()
              << " more miles." << std::endl;

    EfficientCarMilesEstimator myEstimator;
    myEstimator.setGallonsLeft(2);
    std::cout << "Efficient estimator can go " << myEstimator.getMilesLeft()
         << " more miles." << std::endl;

    return 0;
}