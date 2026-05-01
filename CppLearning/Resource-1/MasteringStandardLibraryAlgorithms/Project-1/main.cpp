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
#include <vector>

namespace example
{
    void demo_1()
    {
        int num{};
        std::vector<int> myVector;

        while (true)
        {
            std::cout << " Enter a number to add (0 to stop): ";

            std::cin >> num;

            if (num == 0)
            {
                break;
            }

            myVector.push_back(num);
        }

        while (true)
        {
            std::cout << "Enter a number to lookup (0 to stop): ";

            std::cin >> num;

            if (num == 0)
            {
                break;
            }

            auto endIt = cend(myVector);

            /*
           auto it = find(cbegin(myVector), endIt, num);

            if (it == endIt)
            {
                   cout << "Could not find " << num << endl;
            }
            else
            {
                  cout << "Found " << *it << endl;
            }
            */

            if (auto it = find(cbegin(myVector), endIt, num); it == endIt) // C++17
            {
                std::cout << "Could not find " << num << std::endl;
            }
            else
            {
                std::cout << "Found " << *it << std::endl;
            }
        }
    }

    bool perfectScore(int num)
    {
        return (num >= 100);
    }

    void demo_2()
    {

        int num{};
        std::vector<int> myVector;

        while (true)
        {
            std::cout << " Enter a number to add (0 to stop): ";

            std::cin >> num;

            if (num == 0)
            {
                break;
            }

            myVector.push_back(num);
        }

        auto endIt = cend(myVector);

        /*
       //auto it = find_if(cbegin(myVector), endIt, perfectScore);
       auto it = find_if(cbegin(myVector), endIt, [](int i){ return i >= 100; });

       if (it == endIt)
       {
              std::cout << "No perfect scores" << std::endl;
       }
       else
       {
             std::cout << "Found a \"perfect\" score of " << *it << std::endl;
       }*/

        //if (auto it = find_if(cbegin(myVector), endIt, perfectScore); it == endIt)
        if (auto it = find_if(cbegin(myVector), endIt, [](int i){ return i >= 100; }); it == endIt)
        {
            std::cout << "No perfect scores" << std::endl;
        }
        else
        {
            std::cout << "Found a \"perfect\" score of " << *it << std::endl;
        }
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // example::demo_1();
    example::demo_2();

    return 0;
}