/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief std::list
 *          Splicing
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

    // Store the a words in the main dictionary.
    std::list<std::string> dictionary{"aardvark", "ambulance"};

    // Store the b words.
    std::list<std::string> bWords{"bathos", "balderdash"};

    // Add the c words to the main dictionary.
    dictionary.push_back("canticle");
    dictionary.push_back("consumerism");

    // Splice the b words into the main dictionary.
    if (!bWords.empty())
    {
        // Get an iterator to the last b word.
        auto iterLastB = --(cend(bWords));

        // Iterate up to the spot where we want to insert b words.
        auto it = cbegin(dictionary);

        for (; it != cend(dictionary); ++it)
        {
            if (*it > *iterLastB)
                break;
        }

        // Add in the b words. This action removes the elements from bWords.
        dictionary.splice(it, bWords);
    }

    // Print out the dictionary.
    for (const auto &word : dictionary)
    {
        std::cout << word << std::endl;
    }

    return 0;
}