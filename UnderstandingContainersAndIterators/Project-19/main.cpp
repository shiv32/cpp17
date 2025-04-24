/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief std::list
 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <list>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::list<int> myList = {1, 2, 3, 4};

    // Access elements
    std::cout << "Front: " << myList.front() << "\n";
    std::cout << "Back: " << myList.back() << "\n\n";

    // Add elements
    myList.push_front(0);
    myList.push_back(5);

    auto it = myList.begin();
    std::advance(it, 3);   // Move to 4th position
    myList.insert(it, 99); // Insert 99

    std::cout << "After insertion: ";
    // Iterators
    for (int val : myList) // range-based loop (C++11+)
        std::cout << val << " ";
    std::cout << "\n";

    for (auto it = myList.begin(); it != myList.end(); ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << "\n";

    // Remove elements
    myList.pop_front(); // Remove first
    myList.pop_back();  // Remove last

    it = myList.begin();
    std::advance(it, 2); // Move to 3rd element
    myList.erase(it);    // Remove 3rd element

    myList.remove(3); // Remove all 3s

    std::cout << "After removal: ";
    for (int val : myList)
        std::cout << val << " ";
    std::cout << "\n";

    // Size
    std::cout << "List size: " << myList.size() << "\n";
    std::cout << "Is list empty? " << (myList.empty() ? "Yes" : "No") << "\n";

    return 0;
}