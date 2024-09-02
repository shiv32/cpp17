/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief   Referring to Parent Names
                When you override a method in a derived class, you are effectively replacing 
                the original as far as other code is concerned.
                However, that parent version of the method still exists and you may want
                to make use of it. 

                eg. 
                    Take a look at the getTemperature() method in the WeatherPrediction class 
                    that returns a string representation of the current temperature.

                    virtual std::string getTemperature() const;

                    override this method in the MyWeatherPrediction class.

                    virtual std::string getTemperature() const override;

                    Suppose the derived class wants to add °F to the string by first calling the base class 
                    getTemperature() method and then adding °F to the string.

                    return getTemperature() + "\u00B0F";  //bug

                    However, this does not work because, under the rules of name resolution for C++.
                    It first resolves against the local scope, 
                    then the class scope, 
                    and as a consequence ends up calling MyWeatherPrediction::getTemperature(). 

                    This results in an infinite recursion until you run out of stack space
                    (some compilers detect this error and report it at compile time).

                
   

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