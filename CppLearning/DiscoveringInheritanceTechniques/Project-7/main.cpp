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
                Fundamentally, your program needs something just like the WeatherPrediction class
                but with a few extra bells and whistles. 
                Sounds like a good case for inheritance to reuse code. 
                Define a new class, MyWeatherPrediction, that inherits from WeatherPrediction.

                The MyWeatherPrediction class can already be used in place of WeatherPrediction. 
                It provides exactly the same functionality.

                For the first modification, you might want to add knowledge of the Celsius scale to the class.

                Use the derived class to act as a go-between, interfacing between the user, who can use either
                scale, and the base class, which only understands Fahrenheit.

                The first step in supporting Celsius is to add new methods that allow clients to set the current temperature
                in Celsius instead of Fahrenheit and to get tomorrow’s prediction in Celsius instead of Fahrenheit. 

                You also need private helper methods that convert between Celsius and Fahrenheit in both directions. 
                These methods can be static because they are the same for all instances of the class.

                MyWeatherPrediction object has all of the functionality defined in both MyWeatherPrediction and
                WeatherPrediction. 

                To set the current temperature in Celsius, you need to convert the temperature first and then present it to the parent
                class in units that it understands.

                setCurrentTempFahrenheit(fahrenheitTemp);

                The implementation of getTomorrowTempCelsius() uses the parent’s existing functionality to get the 
                temperature in Fahrenheit, but converts the result before returning it.

                return convertFahrenheitToCelsius(fahrenheitTemp);

                The two new methods effectively reuse the parent class because they “wrap” the existing functionality 
                in a way that provides a new interface for using it.

                You can also add new functionality completely unrelated to existing functionality of the parent
                class. 
                
                eg.
                    you could add a method that retrieves alternative forecasts from the Internet or a
                    method that suggests an activity based on the predicted weather.

            Replacing Functionality in a Derived Class
                The other major technique for inheritance is replacing existing functionality. 

                The showResult() method in the WeatherPrediction class is in dire need of a facelift. 

                MyWeatherPrediction can override this method to replace the behavior with its own implementation.

            To clients using this class, it’s as if the old version of showResult() never existed. 
            As long as the object is a MyWeatherPrediction object, the new version is called.

            As a result of these changes, MyWeatherPrediction has emerged as a new class with new functionality 
            tailored to a more specific purpose. 
            Yet, it did not require much code because it leveraged its base class’s existing functionality.

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