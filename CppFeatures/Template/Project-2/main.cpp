/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Class Templates

 * @version 0.1
 * @date 2024-10-16
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>

/*
class Stack
{
    int m_Buffer[512];
    int m_Top{-1};

public:
    void Push(int elem)
    {
        m_Buffer[++m_Top] = elem;
    }

    void Pop()
    {
        --m_Top;
    }

    int Top() const
    {
        return m_Buffer[m_Top];
    }

    bool IsEmpty()
    {
        return m_Top == -1;
    }
};
*/

template <typename T, int size>
class Stack
{
    T m_Buffer[size];
    int m_Top{-1};

public:
    void Push(const T &elem)
    {
        m_Buffer[++m_Top] = elem;
    }

    void Pop()
    {
        --m_Top;
    }

    const T &Top() const
    {
        return m_Buffer[m_Top];
    }

    bool IsEmpty()
    {
        return m_Top == -1;
    }
};

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    /*
     Stack s;

        s.Push(3);
        s.Push(1);
        s.Push(6);
        s.Push(9);

        while (!s.IsEmpty())
        {
            std::cout << s.Top() << std::endl;
            s.Pop();
        }
    */

    // Stack<int,10> s;
    Stack<float, 10> s;

    s.Push(3);
    s.Push(1);
    s.Push(6);
    s.Push(9);

    while (!s.IsEmpty())
    {
        std::cout << s.Top() << std::endl;
        s.Pop();
    }

    return 0;
}