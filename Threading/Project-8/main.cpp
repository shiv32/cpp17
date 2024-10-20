/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 
        Atomic Operations
        g++ main.cpp -o test && ./test && rm test

 * @version 0.1
 * @date 2024-10-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <atomic>

using namespace std;

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    atomic<int> value(10);

    cout << "Value = " << value << endl;

    int fetched = value.fetch_add(4);

    cout << "Fetched = " << fetched << endl;

    cout << "Value = " << value << endl;

    return 0;
}