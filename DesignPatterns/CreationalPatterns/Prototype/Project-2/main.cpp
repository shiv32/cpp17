/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief ProtoType
 *
 *
 *
 * @version 0.1
 * @date 2024-12-14
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include "PrototypeFactory.hpp"

void Client(PrototypeFactory &prototype_factory)
{
  std::cout << "Let's create a Prototype 1\n";

  Prototype *prototype = prototype_factory.CreatePrototype(Type::PROTOTYPE_1);
  prototype->Method(90);
  delete prototype;

  std::cout << "\n";

  std::cout << "Let's create a Prototype 2 \n";

  prototype = prototype_factory.CreatePrototype(Type::PROTOTYPE_2);
  prototype->Method(10);
  delete prototype;
}

int main()
{

  system("clear && printf '\e[3J'"); // clean the terminal before output in linux

  PrototypeFactory *prototype_factory = new PrototypeFactory();
  
  Client(*prototype_factory);

  delete prototype_factory;

  return 0;
}