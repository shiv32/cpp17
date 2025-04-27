/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Flyweight
 * @version 0.1
 * @date 2024-08-10
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include "FlyweightFactory.hpp"
#include "Flyweight.hpp"
#include "SharedState.hpp"
#include "UniqueState.hpp"

void AddCarToPoliceDatabase(FlyweightFactory &ff,
                            const std::string &plates,
                            const std::string &owner,
                            const std::string &brand,
                            const std::string &model,
                            const std::string &color)
{
    std::cout << "\nClient: Adding a car to database.\n";

    const Flyweight &flyweight = ff.GetFlyweight({brand, model, color});

    // The client code either stores or calculates extrinsic state and passes it
    // to the flyweight's methods.
    flyweight.Operation({owner, plates});
}

int main() // client
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    FlyweightFactory *factory = new FlyweightFactory(
        {{"Chevrolet", "Camaro2018", "pink"},
         {"Mercedes Benz", "C300", "black"},
         {"Mercedes Benz", "C500", "red"},
         {"BMW", "M5", "red"},
         {"BMW", "X6", "white"}});

    factory->ListFlyweights();

    AddCarToPoliceDatabase(*factory,
                           "CL234IR",
                           "James Doe",
                           "BMW",
                           "M5",
                           "red");

    AddCarToPoliceDatabase(*factory,
                           "CL234IR",
                           "James Doe",
                           "BMW",
                           "X1",
                           "red");

    factory->ListFlyweights();

    delete factory;

    return 0;
}