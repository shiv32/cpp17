/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief  vector<bool> Specialization
 *
 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <vector>
#include <thread>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Create a vector<bool> and initialize it
    std::vector<bool> flags = {true, false, true, false, true};

    // Modify an element (uses proxy reference)
    flags[1] = true; // Now the second element is true

    // Print all elements
    std::cout << "Flags: ";
    for (bool flag : flags)
    {
        std::cout << flag << " ";
    }
    std::cout << '\n';

    // Using push_back
    flags.push_back(false);
    flags.push_back(true);

    //---------------------------------------------
    // std::cout << "Before flipping:\n";
    // for (bool flag : flags)
    // {
    //     std::cout << flag << " ";
    // }
    // std::cout << '\n';

    // // Flip each element manually
    // for (size_t i = 0; i < flags.size(); ++i)
    // {
    //     flags[i].flip(); // Flip the boolean value
    // }

    // std::cout << "After flipping:\n";
    // for (bool flag : flags)
    // {
    //     std::cout << flag << " ";
    // }
    // std::cout << '\n';

    //----------------------------------------------------------------

    // Check size and capacity
    // std::cout << "Size: " << flags.size() << ", Capacity: " << flags.capacity() << '\n';

    //-------------------------(common issues)-------------------------
    // 1.
    // std::vector<bool> vec(10, true);
    // bool &ref = vec[0]; // Compilation error: No real reference available

    // char of vector working
    // std::vector<char> vec = {true, false, true};

    // char &ref = vec[0];
    // std::cout << static_cast<int>(ref) << std::endl;

    // ref = false;
    // std::cout << static_cast<int>(vec[0]) << std::endl;

    // char *ptr = vec.data();
    // std::cout << static_cast<int>(ptr[0]) << std::endl;

    // 2.
    /*
    Unlike a standard std::vector<T>, where each element is a direct reference, std::vector<bool> uses bit-packing optimizations.
    Instead of storing bool elements as separate bool objects, it compresses them into bits within a single memory block.
    Because of this optimization, std::vector<bool>::iterator does not return a direct bool& reference. Instead, it returns a
    proxy object (implementation-defined) that behaves like a reference but actually interacts with the bit-packed storage indirectly.
    */

    // std::vector<bool> vec = {true, false, true};
    // std::vector<bool>::iterator it = vec.begin();

    // for (bool elem : vec)
    // {
    //     std::cout << elem << " ";
    // }
    // std::cout << '\n';

    // *it = false; // Works but modifies underlying packed storage indirectly (via proxy)

    // std::cout << "modifies underlying packed storage indirectly:\n";
    // for (bool elem : vec)
    // {
    //     std::cout << elem << " ";
    // }
    // std::cout << '\n';

    // bool b = *it; //you get a temporary bool, not a reference.
    // std::cout << b << std::endl;

    // auto& ref = *it; //compile error: may not work as expected, because *it is a proxy, not a bool&
    // std::cout << ref << std::endl;

    // 3.
    // std::vector<bool> vec(10);
    // bool *ptr = vec.data(); // Compilation error

    return 0;
}