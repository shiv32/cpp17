/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-10-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include "Context.hpp"
#include "ConcreteStateA.hpp"

void ClientCode()
{
      Context *context = new Context(new ConcreteStateA);
      context->Request1();
      //context->Request2();
      delete context;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    ClientCode();
    return 0;
}
