/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Pointers
 * 
                (Process)

                ⬇   stack <- local variables
                ⬆   heap  <- dynamically allocated memory
                    data  <- global and static variables
                    code  <- programs executable code

            (virtual address space)

 * @version 0.1
 * @date 2024-08-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    int data = 30;      //stack
    int *ptr = &data;  //stack

    ptr = new int(7); //heap
    delete ptr;

    return 0;
}