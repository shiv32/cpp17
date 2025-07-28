#include <iostream>
#include "GArray.hpp"

void Print(const Basic::GArray<int> &arr, const char *message)
{
    std::cout << message << std::endl;
    for (int i = 0; i < arr.GetSize(); ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    try
    {
        using namespace Basic;
        GArray<int> arr{1, 2, 3};
        Print(arr, "Initial array");

        arr.Insert(0, 0);
        arr.Insert(3, 4);
        Print(arr, "Insert");

        arr.Erase(0);
        Print(arr, "Erase");
        arr.Erase(3);
        Print(arr, "Erase");
    }
    catch (const std::exception &ex)
    {
        std::cout << "### EXCEPTION ###" << std::endl;
        std::cout << ex.what() << std::endl;
    }

    return 0;
}