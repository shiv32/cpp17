/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Function Template Overloading
 * @version 0.1
 * @date 2025-05-01
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include "funtemplate.hpp"

using optionalValue = std::optional<size_t>;

void printValue(const optionalValue &res)
{
    if (res.has_value())
        std::cout << "index : " << res.value() << std::endl;
    else
        std::cout << "Not found" << std::endl;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    const char *word = "three";
    const char *words[] = {"one", "two", "three", "four"};
    const size_t sizeWords = std::size(words);

    optionalValue res{};

    res = Find<const char *>(word, words, sizeWords); // Calls const char* specialization

    printValue(res);

    res = Find(word, words, sizeWords); // Calls non-template function

    printValue(res);

    return 0;
}