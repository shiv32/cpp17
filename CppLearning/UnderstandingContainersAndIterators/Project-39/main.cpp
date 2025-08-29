/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief unordered_map Example: Phone Book
 * @version 0.1
 * @date 2025-07-03
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include <unordered_map>

void unorderedMapExample()
{
    std::unordered_map<int, std::string> m = {
        {1, "Item 1"},
        {2, "Item 2"},
        {3, "Item 3"},
        {4, "Item 4"}};

    // Using C++17 structured bindings.
    for (const auto &[key, value] : m)
    {
        std::cout << key << " = " << value << std::endl;
    }

    std::cout << "----------------" << std::endl;

    // Without structured bindings.
    for (const auto &p : m)
    {
        std::cout << p.first << " = " << p.second << std::endl;
    }
}

// Phone Book ------------------------------------------
template <class T>
void printMap(const T &m)
{
    for (auto &[key, value] : m)
    {
        std::cout << key << " (Phone: " << value << ")" << std::endl;
    }
    std::cout << "-------" << std::endl;
}

void phoneBook()
{
    // Create a hash table.
    std::unordered_map<std::string, std::string> phoneBook = {
        {"Marc G.", "123-456789"},
        {"Scott K.", "654-987321"}};

    printMap(phoneBook);

    // Add/remove some phone numbers.
    phoneBook.insert(std::make_pair("John D.", "321-987654"));
    phoneBook["Johan G."] = "963-258147";
    phoneBook["Freddy K."] = "999-256256";
    phoneBook.erase("Freddy K.");

    printMap(phoneBook);

    // Find the bucket index for a specific key.
    const size_t bucket = phoneBook.bucket("Marc G.");

    std::cout << "Marc G. is in bucket " << bucket
              << " which contains the following "
              << phoneBook.bucket_size(bucket) << " elements:" << std::endl;

    // Get begin and end iterators for the elements in this bucket.
    // 'auto' is used here. The compiler deduces the type of
    // both as unordered_map<string, string>::const_local_iterator

    auto localBegin = phoneBook.cbegin(bucket);
    auto localEnd = phoneBook.cend(bucket);

    for (auto iter = localBegin; iter != localEnd; ++iter)
    {
        std::cout << "\t" << iter->first << " (Phone: "
                  << iter->second << ")" << std::endl;
    }

    std::cout << "-------" << std::endl;

    // Print some statistics about the hash table
    std::cout << "There are " << phoneBook.bucket_count() << " buckets." << std::endl;
    std::cout << "Average number of elements in a bucket is "
              << phoneBook.load_factor() << std::endl;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // unorderedMapExample();
    phoneBook();

    return 0;
}
