/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Class Templates
            Explicit specialization II

 * @version 0.1
 * @date 2024-10-16
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <vector>

template <typename T>
class PrettyPrinter
{
    T *m_pData{};

public:
    PrettyPrinter(T *data) : m_pData(data)
    {
    }

    void Print()
    {
        std::cout << "{ " << *m_pData << " }" << std::endl;
    }

    T *GetData()
    {
        return m_pData;
    }
};

// Explicit specialization
template <>
class PrettyPrinter<char *>
{
    char *m_pData{};

public:
    PrettyPrinter(char *data) : m_pData(data)
    {
    }

    void Print()
    {
        std::cout << "{ " << m_pData << " }" << std::endl;
    }

    char *GetData()
    {
        return m_pData;
    }
};

//-----------------------(II)------------------------------------
// template <>
// class PrettyPrinter<std::vector<int>>
// {
//     std::vector<int> *m_pData{};

// public:
//     PrettyPrinter(std::vector<int> *data) : m_pData(data)
//     {
//     }

//     void Print()
//     {
//         std::cout << "{ ";

//         for (const auto &x : *m_pData)
//         {
//             std::cout << x;
//         }

//         std::cout << " }" << std::endl;
//     }

//     std::vector<int> *GetData()
//     {
//         return m_pData;
//     }
// };

// Explicit specialization only class member function
template <>
void PrettyPrinter<std::vector<int>>::Print()
{
    std::cout << "{ ";

    for (const auto &x : *m_pData)
    {
        std::cout << x;
    }

    std::cout << " }" << std::endl;
}

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // int data = 5;
    // float floatData = 8.2f;

    // PrettyPrinter<int> p1(&data);
    // p1.Print();

    // PrettyPrinter<float> p2(&floatData);
    // p2.Print();

    // char *p{"Hello World"}; //Compiler: ISO C++ forbids converting a string constant to ‘char*’ [-Wwrite-strings]
    char p[]{"Hello World"};

    PrettyPrinter<char *> p3(p);
    //  PrettyPrinter<char *> p3(&p);
    // PrettyPrinter<char> p3(p);
    p3.Print();

    char *pData = p3.GetData();

    //------------------------------(II)------------------------------
    std::vector<int> v{1, 2, 3, 4, 5};

    PrettyPrinter<std::vector<int>> pv(&v);
    pv.Print();

    return 0;
}