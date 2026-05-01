/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 *
 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <algorithm>
#include <functional>

namespace CMF
{
    void findEmptyString(const std::vector<std::string> &strings)
    {
        auto endIter = std::end(strings);

        // mem_fn() generates a function object that serves as the callback for find_if().
        auto it = find_if(begin(strings), endIter, std::mem_fn(&std::string::empty));

        if (it == endIter)
        {
            std::cout << "No empty strings!" << std::endl;
        }
        else
        {
            std::cout << "Empty string at position: " << static_cast<int>(it - begin(strings)) << std::endl;
        }
    }

    void findEmptyString2(const std::vector<std::string *> &strings)
    {
        auto endIter = std::end(strings);

        // mem_fn() generates a function object that serves as the callback for find_if().
        auto it = find_if(begin(strings), endIter, std::mem_fn(&std::string::empty));

        if (it == endIter)
        {
            std::cout << "No empty strings!" << std::endl;
        }
        else
        {
            std::cout << "Empty string at position: " << static_cast<int>(it - begin(strings)) << std::endl;
        }
    }

    void findEmptyString3(const std::vector<std::string> &strings)
    {
        auto endIter = std::end(strings);

        auto it = find_if(begin(strings), endIter, [](const std::string &str)
                          { return str.empty(); });

        if (it == endIter)
        {
            std::cout << "No empty strings!" << std::endl;
        }
        else
        {
            std::cout << "Empty string at position: " << static_cast<int>(it - begin(strings)) << std::endl;
        }
    }

    void findEmptyString4(const std::vector<std::string *> &strings)
    {
        auto endIter = std::end(strings);

        auto it = find_if(begin(strings), endIter, [](const std::string *str)
                          { return str->empty(); });

        if (it == endIter)
        {
            std::cout << "No empty strings!" << std::endl;
        }
        else
        {
            std::cout << "Empty string at position: " << static_cast<int>(it - begin(strings)) << std::endl;
        }
    }

}

void printMessage(std::string_view message) { std::cout << message << std::endl; }

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::string a = "shiv";
    std::string b = "amit";
    std::string c = "";

    std::vector<std::string *> nameListPtr{&a, &b, &c};

    std::vector<std::string> nameList{"shiv", "amit", "", "manoj"};

    // CMF::findEmptyString(nameList);
    // CMF::findEmptyString2(nameListPtr);
    // CMF::findEmptyString3(nameList);
    // CMF::findEmptyString4(nameListPtr);

    //----------------
    std::string msg = "Hello invoke.";

    std::invoke(printMessage, "Hello invoke.");
    std::invoke([](const auto &msg){ std::cout << msg << std::endl; }, "Hello invoke2.");
    std::cout << std::invoke(&std::string::size, msg) << std::endl;

    return 0;
}