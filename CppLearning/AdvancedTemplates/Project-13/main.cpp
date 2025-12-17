/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-05-01
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>

template <int i>
class Loop
{
public:
    template <typename FuncType>
    static inline void Do(FuncType func)
    {
        Loop<i - 1>::Do(func);
        func(i);
    }
};

template <>
class Loop<0>
{
public:
    template <typename FuncType>
    static inline void Do(FuncType /* func */) {}
};

void DoWork(int i) { std::cout << "DoWork(" << i << ")" << std::endl; }

void DoWork2(std::string str, int i)
{
    std::cout << "DoWork2(" << str << ", " << i << ")" << std::endl;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    Loop<3>::Do(DoWork);

    Loop<2>::Do([](int i)
                { DoWork2("TestStr", i); });

    return 0;
}