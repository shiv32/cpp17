#include <iostream>
#include "Context.hpp"
#include "ConcreteStateA.hpp"

/**
 * The client code.
 */

void ClientCode()
{
      Context *context = new Context(new ConcreteStateA);
      context->Request1();
      context->Request2();
      delete context;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    ClientCode();
    return 0;
}
