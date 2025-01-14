/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Class Templates
            Partial specialization

 * @version 0.1
 * @date 2024-10-16
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <vector>

template <typename T, int columns>
class PrettyPrinter
{
    T *m_pData{};

public:
    PrettyPrinter(T *data) : m_pData(data)
    {
    }

    void Print()
    {
        std::cout << "Columns : " << columns << std::endl;
        std::cout << "{ " << *m_pData << " }" << std::endl;
    }

    T *GetData()
    {
        return m_pData;
    }
};

// partial specialization
template <typename T>
class PrettyPrinter<T, 80>
{

    T *m_pData{};

public:
    PrettyPrinter(T *data) : m_pData(data)
    {
    }

    void Print()
    {
        std::cout << "80 Columns " << std::endl;
        std::cout << "{ " << *m_pData << " }" << std::endl;
    }

    T *GetData()
    {
        return m_pData;
    }
};

//-----------------------------------
template <typename T>
class SmartPointer
{
    T *m_ptr;

public:
    SmartPointer(T *ptr) : m_ptr(ptr) {};

    T *operator->()
    {
        return m_ptr;
    }

    T &operator*()
    {
        return *m_ptr;
    }

    ~SmartPointer()
    {
        delete m_ptr;
    }
};

// partial specialization
template <typename T>
class SmartPointer<T[]>
{
    T *m_ptr;

public:
    SmartPointer(T *ptr) : m_ptr(ptr) {};

    T &operator[](int index)
    {
        return m_ptr[index];
    }

    ~SmartPointer()
    {
        delete[] m_ptr;
    }
};

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    int data = 800;
    // PrettyPrinter<int, 40> p{&data};
    PrettyPrinter<int, 80> p{&data};
    p.Print();

    // smart pointer
    //  SmartPointer<int> s1{new int(30)};
    // std::cout<<*s1<<std::endl;

    SmartPointer<int[]> s1{new int[5]};
    s1[0] = 50;
    std::cout << s1[0] << std::endl;

    return 0;
}