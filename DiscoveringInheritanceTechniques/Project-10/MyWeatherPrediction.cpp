/**
 * @file MyWeatherPrediction.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-08-26
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "MyWeatherPrediction.hpp"

void MyWeatherPrediction::setCurrentTempCelsius(int temp)
{
    //std::cout << __PRETTY_FUNCTION__ << std::endl;
    int fahrenheitTemp = convertCelsiusToFahrenheit(temp);
    setCurrentTempFahrenheit(fahrenheitTemp);
}

int MyWeatherPrediction::getTomorrowTempCelsius() const
{
    //std::cout << __PRETTY_FUNCTION__ << std::endl;
    int fahrenheitTemp = getTomorrowTempFahrenheit();
    return convertFahrenheitToCelsius(fahrenheitTemp);
}

void MyWeatherPrediction::showResult() const
{
    //std::cout << __PRETTY_FUNCTION__ << std::endl;
    std::cout << "Tomorrow's temperature will be "
              << getTomorrowTempCelsius()
              << " degrees Celsius ("
              << getTomorrowTempFahrenheit()
              << " degrees Fahrenheit)"
              << std::endl;

    std::cout << "Chance of rain is "
              << (getChanceOfRain() * 100)
              << " percent"
              << std::endl;

    if (getChanceOfRain() > 0.5)
    {
        std::cout << "Bring an umbrella!" << std::endl;
    }
}

int MyWeatherPrediction::convertCelsiusToFahrenheit(int celsius)
{
    //std::cout << __PRETTY_FUNCTION__ << std::endl;
    return static_cast<int>(celsius * 9.0 / 5 + 32);
}

int MyWeatherPrediction::convertFahrenheitToCelsius(int fahrenheit)
{
    //std::cout << __PRETTY_FUNCTION__ << std::endl;
    return static_cast<int>((fahrenheit - 32) * 5.0 / 9);
}
