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
    return "Empty";
}

// typedef const char *(*PFN)(int);
using PFN = const char *(*)(int); // Type Aliases

// void ShowError(const char *(*pfn)(int))
void ShowError(PFN pfn)
{
}

// typedef std::vector<std::list<std::string>> Names;
using Names = std::vector<std::list<std::string>>;

// template <typename T>
// using Names = std::vector<std::list<T>>;

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // std::vector<std::list<std::string>> names;
    Names names;

    // Names<std::string> names;
    // Names<Names<std::string>> nnames;

    PFN pfn = GetErrorMessage;
    ShowError(pfn);

    return 0;
}