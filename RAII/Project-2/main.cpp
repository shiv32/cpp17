/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief  RAII with Dynamic Memory (Smart Pointers)
 * @version 0.1
 * @date 2024-10-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <memory>

class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource released\n"; }
};

void useResource()
{
    std::unique_ptr<Resource> ptr = std::make_unique<Resource>();
    std::cout << "Using resource\n";
} // `ptr` goes out of scope, and resource is released automatically.

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    useResource();

    std::cout << "main() end.\n";

    return 0;
}