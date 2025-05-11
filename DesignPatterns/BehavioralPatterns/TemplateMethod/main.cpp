/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Template Method
 * @version 0.1
 * @date 2024-08-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <memory>
#include "AbstractClass.hpp"
#include "ConcreteClass1.hpp"
#include "ConcreteClass2.hpp"

void ClientCode(AbstractClass *class_)
{
    class_->TemplateMethod();
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    /*
   std::cout << "Same client code can work with different subclasses:\n";
   ConcreteClass1 *concreteClass1 = new ConcreteClass1;
   ClientCode(concreteClass1);

   std::cout << "\n";

   std::cout << "Same client code can work with different subclasses:\n";
   ConcreteClass2 *concreteClass2 = new ConcreteClass2;
   ClientCode(concreteClass2);

   delete concreteClass1;
   delete concreteClass2;
    */

    // using smart pointer

    std::cout << "Same client code can work with different subclasses:\n";
    auto concreteClass1 = std::make_unique<ConcreteClass1>();
    ClientCode(concreteClass1.get());

    std::cout << "\n";

    std::cout << "Same client code can work with different subclasses:\n";
    auto concreteClass2 = std::make_unique<ConcreteClass2>();
    ClientCode(concreteClass2.get());

    return 0;
}