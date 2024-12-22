/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief ProtoType
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

int main()
{

  system("clear && printf '\e[3J'"); // clean the terminal before output in linux

  std::vector<Stooge*> roles;
  int choice;

  while (true)
  {
    std::cout << "Larry(1) Moe(2) Curly(3) Go(0): ";
    std::cin >> choice;

    if (choice == 0)
      break;
    else if (choice == 1)
      roles.push_back(new Larry);
    else if (choice == 2)
      roles.push_back(new Moe);
    else
      roles.push_back(new Curly);
  }

  for (int i = 0; i < roles.size(); i++)
    roles[i]->slap_stick();

  for (int i = 0; i < roles.size(); i++)
    delete roles[i];

  return 0;
}