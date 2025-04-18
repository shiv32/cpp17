/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief deque
 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <deque>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::deque<int> dq;

    // Push elements at both ends
    dq.push_back(10);
    dq.push_front(5);

    // Access elements
    std::cout << "Front: " << dq.front() << "\n";
    std::cout << "Back: " << dq.back() << "\n";

    // Iterate through the deque
    for (int n : dq)
    {
        std::cout << n << " ";
    }
    std::cout << "\n";

    // Pop from both ends
    dq.pop_back();
    dq.pop_front();

    std::cout << "Size after popping: " << dq.size() << "\n";

    return 0;
}