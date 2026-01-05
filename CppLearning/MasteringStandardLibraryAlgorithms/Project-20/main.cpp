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

namespace replace
{
    /*
        This solution is inefficient and not recommended.
        The correct solution for this problem is the so-called remove-erase-idiom,
        which runs in linear time.
    */
    void removeEmptyStringsWithoutAlgorithms(std::vector<std::string> &strings)
    {

        for (auto iter = begin(strings); iter != end(strings);)
        {
            if (iter->empty())
                iter = strings.erase(iter);
            else
                ++iter;
        }
    }

    void removeEmptyStrings(std::vector<std::string> &strings)
    {
        auto it = remove_if(begin(strings), end(strings), [](const std::string &str)
                            { return str.empty(); });

        // Erase the removed elements.
        strings.erase(it, end(strings));
    }

    void example1()
    {
        std::vector<std::string> myVector = {"", "one", "", "two", "three", "four"};

        for (auto &str : myVector)
        {
            std::cout << "\"" << str << "\"  ";
        }

        std::cout << std::endl;

        removeEmptyStringsWithoutAlgorithms(myVector); // not recommended

        for (auto &str : myVector)
        {
            std::cout << "\"" << str << "\"  ";
        }

        std::cout << std::endl;
    }

    void example2()
    {
        std::vector<std::string> myVector = {"", "one", "", "two", "three", "four"};

        for (auto &str : myVector)
        {
            std::cout << "\"" << str << "\"  ";
        }

        std::cout << std::endl;

        removeEmptyStrings(myVector); // remove-erase-idiom, recommended

        for (auto &str : myVector)
        {
            std::cout << "\"" << str << "\"  ";
        }

        std::cout << std::endl;
    }

}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    replace::example1();
    replace::example2();

    return 0;
}