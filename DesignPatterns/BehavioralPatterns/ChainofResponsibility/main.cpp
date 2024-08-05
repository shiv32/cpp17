/**
 * @file main.cpp
 * @author Shiv Kumar (info.shivcpp@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "MonkeyHandler.hpp"
#include "SquirrelHandler.hpp"
#include "DogHandler.hpp"

#include <iostream>
#include <vector>

/**
 * The client code is usually suited to work with a single handler. In most
 * cases, it is not even aware that the handler is part of a chain.
 */

/**
 * @brief This is clientCode function
 * 
 * @param handler 
 */
void ClientCode(Handler &handler)
{
    std::vector<std::string> food = {"Nut", "Banana", "Cup of coffee"};

    for (const std::string &f : food)
    {
        std::cout << "Client: Who wants a " << f << "?\n";

        const std::string result = handler.Handle(f);

        if (!result.empty())
        {
            std::cout << "  " << result;
        }
        else
        {
            std::cout << "  " << f << " was left untouched.\n";
        }
    }
}

/**
 * The other part of the client code constructs the actual chain.
 */

/**
 * @brief This is entry point of C++.
 * 
 * @return int 
 */
int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    
    MonkeyHandler *monkey = new MonkeyHandler;
    SquirrelHandler *squirrel = new SquirrelHandler;
    DogHandler *dog = new DogHandler;

    monkey->SetNext(squirrel)->SetNext(dog);

    /**
     * The client should be able to send a request to any handler, not just the
     * first one in the chain.
     */
    std::cout << "Chain: Monkey > Squirrel > Dog\n\n";
    ClientCode(*monkey);

    std::cout << "\n";

    std::cout << "Subchain: Squirrel > Dog\n\n";
    ClientCode(*squirrel);

    delete monkey;
    delete squirrel;
    delete dog;

    return 0;
}