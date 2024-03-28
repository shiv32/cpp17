/*
Function Template Overloading

std::optional<size_t> version

g++ -std=c++17 *.cpp -o test
*/

#include <iostream>
#include "funtemplate.hpp"

using namespace std;

int main()
{
    const char *word = "three";

    const char *words[] = {"one", "two", "three", "four"};

    const size_t sizeWords = std::size(words);

    std::optional<size_t> res;

    // Calls const char* specialization
    res = Find<const char *>(word, words, sizeWords);

    if (res.has_value())
        cout << "index : " << res.value() << endl;
    else
        cout << "Not found" << endl;

    // Calls non-template function
    res = Find(word, words, sizeWords);

    if (res.has_value())
        cout << "index : " << res.value() << endl;
    else
        cout << "Not found" << endl;

    return 0;
}