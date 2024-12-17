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
    Stack() = default;

    Stack(const Stack &obj);

    // Stack(const Stack &obj)
    // Stack(const Stack<T, size> &obj)
    // {
    //     m_Top = obj.m_Top;

    //     for (int i = 0; i <= m_Top; ++i)
    //     {
    //         m_Buffer[i] = obj.m_Buffer[i];
    //     }
    // }

    void Push(const T &elem)
    {
        m_Buffer[++m_Top] = elem;
    }

    void Pop();
    // void Pop()
    // {
    //     --m_Top;
    // }

    const T &Top() const
    {
        return m_Buffer[m_Top];
    }

    bool IsEmpty()
    {
        return m_Top == -1;
    }

    // static Stack Create() //factory
    // {
    //     return Stack<T, size>();
    // }

    static Stack Create(); // factory
};

template <typename T, int size>
void Stack<T, size>::Pop()
{
    --m_Top;
}

template <typename T, int size>
Stack<T, size> Stack<T, size>::Create() // factory
{
    return Stack<T, size>();
}

template <typename T, int size>
// Stack<T, size>::Stack(const Stack &obj)   //working
Stack<T, size>::Stack(const Stack<T, size> &obj)
{
    m_Top = obj.m_Top;

    for (int i = 0; i <= m_Top; ++i)
    {
        m_Buffer[i] = obj.m_Buffer[i];
    }
}

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
    // Stack<float, 10> s;
    Stack<float, 10> s = Stack<float, 10>::Create();

    s.Push(3);
    s.Push(1);
    s.Push(6);
    s.Push(9);

    // std::cout << "s: " << std::endl;

    // while (!s.IsEmpty())
    // {
    //     std::cout << s.Top() << std::endl;
    //     s.Pop();
    // }

    auto s2(s);

    std::cout << "s2: " << std::endl;

    while (!s2.IsEmpty())
    {
        std::cout << s2.Top() << std::endl;
        s2.Pop();
    }

    return 0;
}