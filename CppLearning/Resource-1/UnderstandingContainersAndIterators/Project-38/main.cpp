/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Hash Functions: custom hash function
 * @version 0.1
 * @date 2025-07-03
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include <functional>
#include <unordered_set>
#include <unordered_map>

class IntWrapper
{
public:
    IntWrapper(int i) : mWrappedInt(i) {}
    int getValue() const { return mWrappedInt; }

private:
    int mWrappedInt;
};

bool operator==(const IntWrapper &lhs, const IntWrapper &rhs)
{
    return lhs.getValue() == rhs.getValue();
}

namespace std
{
    template <>
    struct hash<IntWrapper>
    {
        using argument_type = IntWrapper;
        using result_type = size_t;

        result_type operator()(const argument_type &f) const
        {
            // std::clog << __PRETTY_FUNCTION__ << std::endl;
            return std::hash<int>()(f.getValue());
        }
    };
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Using IntWrapper in an unordered_set
    std::unordered_set<IntWrapper> s;
    s.insert(IntWrapper{10});
    s.insert(IntWrapper{20});
    s.insert(IntWrapper{10}); // duplicate, won't be added

    std::cout << "unordered_set contents:\n";
    for (const auto &item : s)
    {
        std::cout << item.getValue() << '\n';
    }

    // Using IntWrapper as key in an unordered_map
    std::unordered_map<IntWrapper, std::string> m;
    m[IntWrapper{1}] = "one";
    m[IntWrapper{2}] = "two";

    std::cout << "unordered_map contents:\n";
    // for (const auto &kv : m)
    // {
    //     std::cout << kv.first.getValue() << " => " << kv.second << '\n';
    // }

    //or
    for (const auto &[key, value] : m) // C++ structured bindings
    {
        std::cout << key.getValue() << " => " << value << '\n';
    }

    // Looking up values
    IntWrapper key{2};
    auto it = m.find(key);
    if (it != m.end())
    {
        // std::cout << "Found key " << it->first.getValue() << " with value " << it->second << '\n';

        // or
        const auto &[key, value] = *it; // C++ structured binding
        std::cout << "Found key " << key.getValue()
                  << " with value " << value << '\n';
    }

    return 0;
}
