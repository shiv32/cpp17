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
#include <algorithm>
#include <memory>
#include <functional>

namespace GLE
{
    // Define a generic lambda to find values > 100.
    auto isGreaterThan100 = [](auto i)
    { return i > 100; };

    void genericLambdaExpressions1()
    {
        // Use the generic lambda with a vector of integers.
        std::vector<int> ints{11, 55, 101, 200};
        auto it1 = find_if(cbegin(ints), cend(ints), isGreaterThan100);

        if (it1 != cend(ints))
        {
            std::cout << "Found a value > 100: " << *it1 << std::endl;
        }
    }

    void genericLambdaExpressions2()
    {
        // Use exactly the same generic lambda with a vector of doubles.
        std::vector<double> doubles{11.1, 55.5, 200.2};
        auto it2 = find_if(cbegin(doubles), cend(doubles), isGreaterThan100);
        if (it2 != cend(doubles))
        {
            std::cout << "Found a value > 100: " << *it2 << std::endl;
        }
    }
}

namespace LCE
{
    void lambdaCaptureExpressions1()
    {
        double pi = 3.1415;
        auto myLambda = [myCapture = "Pi: ", pi]
        { std::cout << myCapture << pi; };
        myLambda();
        std::cout << std::endl;
    }

    void lambdaCaptureExpressions2()
    {
        auto myPtr = std::make_unique<double>(3.1415);
        auto myLambda = [p = std::move(myPtr)]
        { std::cout << *p; };
        myLambda();
        std::cout << std::endl;
    }

    void lambdaCaptureExpressions3()
    {
        auto myPtr = std::make_unique<double>(3.1415);
        // not recommended, to have the same name for the capture variable as the name in the enclosing scope.
        auto myLambda = [myPtr = std::move(myPtr)]
        { std::cout << *myPtr; };
        myLambda();
        std::cout << std::endl;
    }
}

namespace LERT
{
    std::function<int(void)> multiplyBy2Lambda(int x)
    {
        return [x]{ return 2 * x; };
    }

    auto multiplyBy2Lambda2(int x)
    {
        return [x]{ return 2 * x; };
    }

    auto multiplyBy2Lambda3(int x)
    {
        return [&x]{ return 2 * x; }; // BUG!
    }

    void example1()
    {
        std::function<int(void)> fn = multiplyBy2Lambda(5);
        std::cout << fn() << std::endl;
    }

    void example2()
    {
        auto fn = multiplyBy2Lambda(5);
        std::cout << fn() << std::endl;
    }

    void example3()
    {
        std::function<int(void)> fn = multiplyBy2Lambda2(5);
        std::cout << fn() << std::endl;
    }

    void example4()
    {
        auto fn = multiplyBy2Lambda2(5);
        std::cout << fn() << std::endl;
    }

    void example5()
    {
        std::function<int(void)> fn = multiplyBy2Lambda3(5);
        std::cout << fn() << std::endl;
    }

    void example6()
    {
        auto fn = multiplyBy2Lambda3(5);
        std::cout << fn() << std::endl;
    }
}

namespace LEP
{
    //check std::function examples
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // GLE::genericLambdaExpressions1();
    // GLE::genericLambdaExpressions2();

    // LCE::lambdaCaptureExpressions1();
    // LCE::lambdaCaptureExpressions2();
    // LCE::lambdaCaptureExpressions3();

    LERT::example1();
    LERT::example2();
    LERT::example3();
    LERT::example4();
    LERT::example5();// BUG!
    LERT::example6();// BUG!

    return 0;
}