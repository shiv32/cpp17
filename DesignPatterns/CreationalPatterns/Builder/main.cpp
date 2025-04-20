/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Builder
 * @version 0.1
 * @date 2024-12-14
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include "Director.hpp"
#include "ConcreteBuilder1.hpp"

void ClientCode(Director &director)
{
  //------------------------------------------------------------
  ConcreteBuilder1 *builder = new ConcreteBuilder1();

  director.set_builder(builder);
  std::cout << "Standard basic product:\n";
  director.BuildMinimalViableProduct();

  Product1 *p = builder->GetProduct();
  p->ListParts();
  delete p;
  //------------------------------------------------------------

  //------------------------------------------------------------
  std::cout << "Standard full featured product:\n";
  director.BuildFullFeaturedProduct();

  p = builder->GetProduct();
  p->ListParts();
  delete p;
  //------------------------------------------------------------

  //------------------------------------------------------------
  // Remember, the Builder pattern can be used without a Director class.
  std::cout << "Custom product:\n";
  builder->ProducePartA();
  builder->ProducePartC();
  p = builder->GetProduct();
  p->ListParts();
  delete p;
  //-------------------------------------------------------------

  delete builder;
}

int main()
{

  system("clear && printf '\e[3J'"); // clean the terminal before output in linux

  Director *director = new Director();
  ClientCode(*director);
  delete director;

  return 0;
}