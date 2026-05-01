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

namespace ctd
{
    template <typename InputIterator, typename OutputIterator, typename Predicate>
    OutputIterator find_all(InputIterator first, InputIterator last, OutputIterator dest, Predicate pred)
    {
        while (first != last)
        {
            if (pred(*first))
            {
                *dest = first;
                ++dest;
            }
            ++first;
        }
        return dest;
    }

    template <typename IteratorType>
    void iteratorTraitsTest(IteratorType it)
    {
        typename std::iterator_traits<IteratorType>::value_type temp;
        temp = *it;
        cout << temp << endl;
    }

    template <typename IteratorType>
    void iteratorTraitsTest2(IteratorType it)
    {
        auto temp = *it;
        cout << temp << endl;
    }
}

namespace sla
{
    void example1()
    {
        vector<int> vec{3, 4, 5, 4, 5, 6, 5, 8};
        vector<vector<int>::iterator> matches;

        ctd::find_all(begin(vec), end(vec), back_inserter(matches), [](int i)
                      { return i == 5; });

        cout << "Found " << matches.size() << " matching elements: " << endl;

        for (const auto &it : matches)
        {
            cout << *it << " at position " << (it - cbegin(vec)) << endl;
        }
    }
}

namespace it
{
    void example1()
    {
        vector<int> v{5};
        ctd::iteratorTraitsTest(cbegin(v));
    }

    void example2()
    {
        vector<int> v{5};
        ctd::iteratorTraitsTest2(cbegin(v));
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // sla::example1();

    // it::example1();
    it::example2();

    return 0;
}