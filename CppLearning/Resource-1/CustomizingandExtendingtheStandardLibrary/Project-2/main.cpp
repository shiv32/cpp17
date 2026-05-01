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
#include <iterator>
#include <vector>
#include <algorithm>
#include <set>

// Function template to populate a container of ints.
// The container must support push_back().
template <typename Container>
void populateContainer(Container &cont)
{
    int num;
    while (true)
    {
        std::cout << "Enter a number (0 to quit): ";
        std::cin >> num;

        if (num == 0)
        {
            break;
        }

        cont.push_back(num);
    }
}

namespace ri
{
    void example1()
    {
        std::vector<int> myVector;
        populateContainer(myVector);

        int num;
        std::cout << "Enter a number to find: ";
        std::cin >> num;

        auto it1 = find(begin(myVector), end(myVector), num);
        auto it2 = find(rbegin(myVector), rend(myVector), num);

        if (it1 != end(myVector))
        {
            std::cout << "Found " << num << " at position " << it1 - begin(myVector)
                      << " going forward." << std::endl;

            std::cout << "Found " << num << " at position "
                      << it2.base() - 1 - begin(myVector) << " going backward." << std::endl;
        }
        else
        {
            std::cout << "Failed to find " << num << std::endl;
        }
    }
}

namespace ii
{
    void example1()
    {
        std::vector<int> vectorOne, vectorTwo;
        populateContainer(vectorOne);

        std::back_insert_iterator<std::vector<int>> inserter(vectorTwo);

        copy_if(cbegin(vectorOne), cend(vectorOne), inserter,
                [](int i)
                { return i != 100; });

        copy(cbegin(vectorTwo), cend(vectorTwo), std::ostream_iterator<int>(std::cout, " "));

        std::cout << std::endl;
    }

    void example2()
    {
        std::vector<int> vectorOne, vectorTwo;
        populateContainer(vectorOne);

        copy_if(cbegin(vectorOne), cend(vectorOne), std::back_inserter(vectorTwo),
                [](int i)
                { return i != 100; });

        copy(cbegin(vectorTwo), cend(vectorTwo), std::ostream_iterator<int>(std::cout, " "));

        std::cout << std::endl;
    }

    void example3()
    {
        std::vector<int> vectorOne, vectorTwo;
        populateContainer(vectorOne);

        copy_if(cbegin(vectorOne), cend(vectorOne), std::back_insert_iterator(vectorTwo),
                [](int i)
                { return i != 100; });

        copy(cbegin(vectorTwo), cend(vectorTwo), std::ostream_iterator<int>(std::cout, " "));

        std::cout << std::endl;
    }

    void example4()
    {
        std::vector<int> vectorOne;
        std::set<int> setOne;
        populateContainer(vectorOne);

        std::insert_iterator<std::set<int>> inserter(setOne, begin(setOne));

        copy_if(cbegin(vectorOne), cend(vectorOne), inserter,
                [](int i)
                { return i != 100; });

        copy(cbegin(setOne), cend(setOne), std::ostream_iterator<int>(std::cout, " "));

        std::cout << std::endl;
    }

    void example5()
    {
        std::vector<int> vectorOne;
        std::set<int> setOne;
        populateContainer(vectorOne);

        copy_if(cbegin(vectorOne), cend(vectorOne), std::inserter(setOne, begin(setOne)),
                [](int i)
                { return i != 100; });

        copy(cbegin(setOne), cend(setOne), std::ostream_iterator<int>(std::cout, " "));

        std::cout << std::endl;
    }

    void example6()
    {
        std::vector<int> vectorOne;
        std::set<int> setOne;
        populateContainer(vectorOne);

        // C++17’s template argument deduction for constructors
        copy_if(cbegin(vectorOne), cend(vectorOne), std::insert_iterator(setOne, begin(setOne)),
                [](int i)
                { return i != 100; });

        copy(cbegin(setOne), cend(setOne), std::ostream_iterator<int>(std::cout, " "));

        std::cout << std::endl;
    }
}

namespace mi
{
    class MoveableClass
    {
    public:
        MoveableClass()
        {
            std::cout << "Default constructor" << std::endl;
        }

        MoveableClass(const MoveableClass &src)
        {
            std::cout << "Copy constructor" << std::endl;
        }

        MoveableClass(MoveableClass &&src) noexcept
        {
            std::cout << "Move constructor" << std::endl;
        }

        MoveableClass &operator=(const MoveableClass &rhs)
        {
            std::cout << "Copy assignment operator" << std::endl;
            return *this;
        }
        
        MoveableClass &operator=(MoveableClass &&rhs) noexcept
        {
            std::cout << "Move assignment operator" << std::endl;
            return *this;
        }
    };

    void example1()
    {
        std::vector<MoveableClass> vecSource;
        MoveableClass mc;
        vecSource.push_back(mc);
        vecSource.push_back(mc);
    }

    void example2()
    {
        std::vector<MoveableClass> vecSource;
        MoveableClass mc;
        vecSource.push_back(mc);
        vecSource.push_back(mc);

        std::vector<MoveableClass> vecOne(cbegin(vecSource), cend(vecSource));
    }

    void example3()
    {
        std::vector<MoveableClass> vecSource;
        MoveableClass mc;
        vecSource.push_back(mc);
        vecSource.push_back(mc);

        std::vector<MoveableClass> vecTwo(make_move_iterator(begin(vecSource)), make_move_iterator(end(vecSource)));
    }

    void example4()
    {
        std::vector<MoveableClass> vecSource;
        MoveableClass mc;
        vecSource.push_back(mc);
        vecSource.push_back(mc);

        // C++17’s template argument deduction for constructors
        std::vector<MoveableClass> vecTwo(std::move_iterator(begin(vecSource)), std::move_iterator(end(vecSource)));
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // ri::example1();

    // ii::example1();
    // ii::example2();
    // ii::example3();
    // ii::example4();
    // ii::example5();
    // ii::example6();

    // mi::example1();
    // mi::example2();
    // mi::example3();
    mi::example4();

    return 0;
}