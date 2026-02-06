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
#include <vector>
#include <iterator>

using namespace std;

namespace hf
{
    template <typename T>
    class hash
    {
    public:
        size_t operator()(const T &key) const;
    };

    // Calculate a hash by treating the key as a sequence
    // of bytes and summing the ASCII values of the bytes.
    template <typename T>
    size_t hash<T>::operator()(const T &key) const
    {
        clog << "no specialization" << endl;

        const size_t bytes = sizeof(key);

        size_t sum = 0;

        for (size_t i = 0; i < bytes; ++i)
        {
            unsigned char b = *(reinterpret_cast<const unsigned char *>(&key) + i);
            sum += b;
        }

        return sum;
    }

    // A hash specialization for strings
    template <>
    class hash<std::string>
    {
    public:
        size_t operator()(const std::string &key) const;
    };

    // Calculate a hash by summing the ASCII values of all characters.
    size_t hash<std::string>::operator()(const std::string &key) const
    {
        clog << "string specialization" << endl;

        size_t sum = 0;

        for (auto c : key)
        {
            sum += static_cast<unsigned char>(c);
        }

        return sum;
    }

    void example1()
    {
        hash<int> hf;
        size_t value = hf(42); // calls operator()
        cout << value << endl;

        hash<int> hf2;
        value = hf2(300); // calls operator()
        cout << value << endl;
    }

    void example2()
    {
        hash<string> hf;
        size_t value = hf("shiv"); // calls operator()
        cout << value << endl;

        hash<string> hf2;
        value = hf2("shiv kumar"); // calls operator()
        cout << value << endl;
    }

    void example3()
    {
        hash<const char *> hf;
        size_t value = hf("shiv"); // calls operator()
        cout << value << endl;

        hash<const char *> hf2;
        value = hf2("shiv kumar"); // calls operator()
        cout << value << endl;
    }

}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // hf::example1();
    // hf::example2();
    hf::example3();

    return 0;
}