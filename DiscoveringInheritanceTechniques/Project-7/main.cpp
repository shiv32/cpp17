/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief   INHERITANCE FOR REUSE
                Inheritance is a vehicle that allows you to leverage existing code. 
                Inheritance is for the purpose of code reuse.

            The WeatherPrediction Class
                Writing a program to issue simple weather predictions, working with both Fahrenheit and Celsius. 

                Weather predictions may be a little bit out of your area of expertise as a programmer, so you obtain 
                a third-party class library that was written to make weather predictions based on the current 
                temperature and the current distance between Jupiter and Mars (hey, it’s plausible).

                This third-party package is distributed as a compiled library to protect
                the intellectual property of the prediction algorithms.

                Note that this class marks all methods as virtual, because the class presumes that 
                its methods might be overridden in a derived class.

                This class solves most of the problems for your program.

                However, as is usually the case, 
                it’s not exactly right for your needs. 

                First, all the temperatures are given in Fahrenheit. Your program needs
                to operate in Celsius as well. 

                Also, the showResult() method might not display the result in a way
                you require.

            Adding Functionality in a Derived Class



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

    std::cout << mwp->getTomorrowTempCelsius() << std::endl;

    mwp->setCurrentTempCelsius(240);

    mwp->showResult();

    return 0;
}