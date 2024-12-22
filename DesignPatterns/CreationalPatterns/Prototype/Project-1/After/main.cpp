/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief ProtoType
 *
 *  A clone() method has been added to the Stooge hierarchy.
 *
 *  A Factory class has been introduced that maintains a
 *  suite of "breeder" objects (aka proto- types), and knows
 *  how to delegate to the correct prototype.
 *
 *
 * @version 0.1
 * @date 2024-12-14
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <vector>
#include "Larry.hpp"
#include "Moe.hpp"
#include "Curly.hpp"
#include "Factory.hpp"

int main()
{

  system("clear && printf '\e[3J'"); // clean the terminal before output in linux

  std::vector<Stooge *> roles;
  int choice;

  while (true)
  {
    std::cout << "Larry(1) Moe(2) Curly(3) Go(0): ";

    std::cin >> choice;

    if (choice == 0)
      break;

    roles.push_back(Factory::make_stooge(choice));
  }

  for (int i = 0; i < roles.size(); ++i)
    roles[i]->slap_stick();

  for (int i = 0; i < roles.size(); ++i)
    delete roles[i];

  return 0;
}