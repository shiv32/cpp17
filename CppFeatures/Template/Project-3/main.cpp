/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Class Templates
            Explicit specialization

 * @version 0.1
 * @date 2024-10-16
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>

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

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // int data = 5;
    // float floatData = 8.2f;

    // PrettyPrinter<int> p1(&data);
    // p1.Print();

    // PrettyPrinter<float> p2(&floatData);
    // p2.Print();

    char *p{"Hello World"};

    PrettyPrinter<char *> p3(p);
    //  PrettyPrinter<char *> p3(&p);
    // PrettyPrinter<char> p3(p);
    p3.Print();

    char *pData = p3.GetData();

    return 0;
}