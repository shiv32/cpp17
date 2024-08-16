/**
 * @file Derived.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-08-11
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Derived.hpp"

 void Derived::someMethod(double d) 
//void Derived::someMethod(int i) 
{
  std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void Derived::someOtherMethod() 
{
  std::cout << __PRETTY_FUNCTION__ << std::endl;

  std::cout << "I can access base class data member mProtectedInt."
            << std::endl;
  std::cout << "Its value is " << mProtectedInt << std::endl;
  // std::cout << "The value of mPrivateInt is " << mPrivateInt << std::endl; //
  // Error!
}