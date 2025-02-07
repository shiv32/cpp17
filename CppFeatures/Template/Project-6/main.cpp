/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Class Templates
            Type Aliases

 * @version 0.1
 * @date 2024-10-16
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <vector>
#include <list>

const char *GetErrorMessage(int errorNo)
{
    switch (errorNo)
    {
    case 10:
        return "Error is 10";
        break;
    case 20:
        return "Error is 20";
        break;
    default:
        return "Error is default";
        break;
    }
    // return "Empty";
}

// typedef const char *(*PFN)(int);
using PFN = const char *(*)(int); // Type Aliases

// void ShowError(const char *(*pfn)(int))
// void ShowError(PFN pfn)
// {
//     std::cout<<pfn(1)<<std::endl;
// }
void ShowError(PFN pfn, int errorNo)
{
    std::cout << pfn(errorNo) << std::endl;
}

// typedef std::vector<std::list<std::string>> Names;
using Names = std::vector<std::list<std::string>>;

// template <typename T>
// using Names = std::vector<std::list<T>>;

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // std::vector<std::list<std::string>> names;
    // Names names;

    // Names<std::string> names;
    // Names<Names<std::string>> nnames;

    PFN pfn = GetErrorMessage;
    // ShowError(pfn);
    ShowError(pfn, 10);

    return 0;
}