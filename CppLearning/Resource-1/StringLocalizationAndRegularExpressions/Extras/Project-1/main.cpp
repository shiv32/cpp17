#include <iostream>
#include <locale>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Character Classification
    bool result = isupper('A', std::locale(""));
    std::cout << "isupper: " << result << '\n';

    // Character Conversion

    std::locale loc; // default locale (can also use std::locale("en_US.UTF-8"))
    // std::locale loc("en_US.UTF-8");
    // std::locale loc("de_DE.UTF-8");

    std::string text = "Hello World! 123 äöü";

    // Convert to uppercase
    std::string upper;
    for (char ch : text)
    {
        upper += std::toupper(ch, loc); // locale-aware
    }

    // Convert to lowercase
    std::string lower;
    for (char ch : text)
    {
        lower += std::tolower(ch, loc); // locale-aware
    }

    std::cout << "Original : " << text << '\n';
    std::cout << "Uppercase: " << upper << '\n';
    std::cout << "Lowercase: " << lower << '\n';

    return 0;
}