/*
  Factory
*/

#include <iostream>
#include <memory>
#include "ConcreteCreator1.hpp"
#include "ConcreteCreator2.hpp"

// void ClientCode(const Creator &creator)
// {

//   std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
//             << creator.SomeOperation() << std::endl;
// }

// using smart pointer
void ClientCode(std::unique_ptr<Creator> creator)
{

  std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
            << creator->SomeOperation() << std::endl;
}

int main()
{

  system("clear && printf '\e[3J'"); // clean the terminal before output in linux

  /*
   std::cout << "App: Launched with the ConcreteCreator1.\n";
   Creator *creator = new ConcreteCreator1();
   ClientCode(*creator);

   std::cout << std::endl;

   std::cout << "App: Launched with the ConcreteCreator2.\n";

   Creator *creator2 = new ConcreteCreator2();
   ClientCode(*creator2);

   delete creator;
   delete creator2;
 */

  // using smart pointer
  std::cout << "App: Launched with the ConcreteCreator1.\n";
  std::unique_ptr<Creator> creator = std::make_unique<ConcreteCreator1>();
  ClientCode(std::move(creator));

  std::cout << std::endl;

  std::cout << "App: Launched with the ConcreteCreator2.\n";
  std::unique_ptr<Creator> creator2 = std::make_unique<ConcreteCreator2>();
  ClientCode(std::move(creator2));

  return 0;
}