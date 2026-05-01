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
#include <string_view>

// Function template to populate a container of ints.
// The container must support push_back().
template <typename Container>
void populateContainer(Container &cont)
{
    int num;
    while (true)
    {
        std::cout << "Enter a number (0 to quit): ";
        std::cin >> num;

        if (num == 0)
        {
            break;
        }

        cont.push_back(num);
    }
}

template <typename Iterator>
void DumpRange(std::string_view message, Iterator begin, Iterator end)
{
    std::cout << message;
    for_each(begin, end, [](const auto &element)
             { std::cout << element << " "; });
    std::cout << std::endl;
}

namespace sa
{
    void example1()
    {
        std::vector<int> vec1, vec2, result;

        std::cout << "Enter elements for set 1:" << std::endl;
        populateContainer(vec1);

        std::cout << "Enter elements for set 2:" << std::endl;
        populateContainer(vec2);

        // set algorithms work on sorted ranges
        sort(begin(vec1), end(vec1));
        sort(begin(vec2), end(vec2));

        DumpRange("Set 1: ", cbegin(vec1), cend(vec1));
        DumpRange("Set 2: ", cbegin(vec2), cend(vec2));

        if (includes(cbegin(vec1), cend(vec1), cbegin(vec2), cend(vec2)))
        {
            std::cout << "The second set is a subset of the first." << std::endl;
        }

        if (includes(cbegin(vec2), cend(vec2), cbegin(vec1), cend(vec1)))
        {
            std::cout << "The first set is a subset of the second" << std::endl;
        }

        result.resize(size(vec1) + size(vec2));

        auto newEnd = set_union(cbegin(vec1), cend(vec1), cbegin(vec2), cend(vec2), begin(result));
        DumpRange("The union is: ", begin(result), newEnd);

        newEnd = set_intersection(cbegin(vec1), cend(vec1), cbegin(vec2), cend(vec2), begin(result));
        DumpRange("The intersection is: ", begin(result), newEnd);

        newEnd = set_difference(cbegin(vec1), cend(vec1), cbegin(vec2), cend(vec2), begin(result));
        DumpRange("The difference between set 1 and 2 is: ", begin(result), newEnd);

        newEnd = set_symmetric_difference(cbegin(vec1), cend(vec1), cbegin(vec2), cend(vec2), begin(result));
        DumpRange("The symmetric difference is: ", begin(result), newEnd);
    }

    //merge() algorithm 
    void example2()
    {
        std::vector<int> vectorOne, vectorTwo, vectorMerged;

        std::cout << "Enter values for first vector:" << std::endl;
        populateContainer(vectorOne);

        std::cout << "Enter values for second vector:" << std::endl;
        populateContainer(vectorTwo);

        // Sort both containers
        sort(begin(vectorOne), end(vectorOne));
        sort(begin(vectorTwo), end(vectorTwo));

        // Make sure the destination vector is large enough to hold the values
        // from both source vectors.
        vectorMerged.resize(size(vectorOne) + size(vectorTwo));

        merge(cbegin(vectorOne), cend(vectorOne), cbegin(vectorTwo), cend(vectorTwo), begin(vectorMerged));

        DumpRange("Merged vector: ", cbegin(vectorMerged), cend(vectorMerged));
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // sa::example1();
    sa::example2();

    return 0;
}