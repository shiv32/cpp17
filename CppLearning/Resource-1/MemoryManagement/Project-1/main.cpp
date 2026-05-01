#include <iostream>

int main() 
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    int value = 10;
    int *ptr1 = &value;

    std::cout << &value << "\n";
    std::cout << value << "\n";

    std::cout << &ptr1 << "\n";
    std::cout << ptr1 << "\n";
    std::cout << *ptr1 << "\n";

    int **handlee = &ptr1;

    std::cout << handlee << "\n";
    std::cout << *handlee << "\n";
    std::cout << **handlee << "\n";

    std::cout << "-----------------------------------------\n";

    int i = 7;

    std::cout << &i << "\n";
    std::cout << i << "\n";

    int *ptr = nullptr; // int* ptr = new int;
    // ptr = new int;
    ptr = new int(45);

    std::cout << &ptr << "\n";
    std::cout << ptr << "\n";
    std::cout << *ptr << "\n";

    int **handle = nullptr;
    handle = new int *;
    *handle = new int(6);

    std::cout << &handle << "\n";
    std::cout << handle << "\n";
    std::cout << *handle << "\n";
    std::cout << **handle << "\n";

    return 1;
}