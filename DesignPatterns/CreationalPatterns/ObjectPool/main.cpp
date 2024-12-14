/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Object Pool
 * @version 0.1
 * @date 2024-12-14
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include "ObjectPool.hpp"

int main()
{

  system("clear && printf '\e[3J'"); // clean the terminal before output in linux

  ObjectPool *pool = ObjectPool::getInstance();
  Resource *one;
  Resource *two;

  /* Resources will be created. */
  one = pool->getResource();
  one->setValue(10);
  std::cout << "one = " << one->getValue() << " [" << one << "]" << std::endl;
  
  two = pool->getResource();
  two->setValue(20);
  std::cout << "two = " << two->getValue() << " [" << two << "]" << std::endl;
  
  pool->returnResource(one);
  pool->returnResource(two);

  /* Resources will be reused.
   * Notice that the value of both resources were reset back to zero.
   */
  one = pool->getResource();
  std::cout << "one = " << one->getValue() << " [" << one << "]" << std::endl;
  
  two = pool->getResource();
  std::cout << "two = " << two->getValue() << " [" << two << "]" << std::endl;

  return 0;
}