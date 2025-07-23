#pragma once
#include "utils.hpp"

namespace Basic
{
    template <typename T>
    class GArray
    {
    public:
        using size_type = size_t;
        using value_type = T;
        using pointer = T *;
        using const_pointer = const T *;
        using reference = T &;
        using const_reference = const T &;

        GArray() = default;
        GArray(size_type count, const_reference elem)
        {
            m_pBuffer = new T[count];

            for (int i = 0; i < count; ++i)
            {
                m_pBuffer[i] = elem;
            }

            m_Size = count;
        };

        GArray(std::initializer_list<value_type> list)
        {
            m_pBuffer = new T[list.size()];
            Copy(list.begin(), list.end(), m_pBuffer);
            m_Size = list.size();
        };

        // Rule of Five
        GArray(const GArray<T> &other) {};
        GArray(GArray<T> &&other) {};
        GArray<T> &operator=(const GArray<T> &other) {};
        GArray<T> &operator=(GArray<T> &&other) {};
        ~GArray()
        {
            delete[] m_pBuffer;
        };

        void Add(const_reference elem) {};
        void Insert(size_type index, const_reference elem) {};
        void Erase(size_type index) {};

        const_reference Back() const
        {
            assert(!Empty());
            return m_pBuffer[m_Size];
        };

        const_reference Front() const
        {
            assert(!Empty());
            return m_pBuffer[0];
        };

        const_reference operator[](size_type index) const
        {
            assert(!Empty());
            return m_pBuffer[index];
        };
        reference operator[](size_type index)
        {
            assert(!Empty());
            return m_pBuffer[index];
        };
        const_reference GetAt(size_type index) const
        {
            if (index > m_Size)
            {
                throw std::runtime_error{"Bad index"};
            }
            return m_pBuffer[index];
        };
        reference GetAt(size_type index)
        {
            if (index > m_Size)
            {
                throw std::runtime_error{"Bad index"};
            }
            return m_pBuffer[index];
        };
        bool Empty() const
        {
            return m_Size == 0;
        };
        size_type GetSize() const
        {
            return m_Size;
        };
        void Clear()
        {
            delete[] m_pBuffer;
        };
        size_type Find(const_reference elem)
        {
            for (int i = 0; i < m_Size; ++i)
            {
                if (m_pBuffer[i] == elem)
                    return i;
            }
            return -1;
        };
        pointer GetRawPointer()
        {
            assert(!Empty());
            return m_pBuffer;
        };
        const_pointer GetRawPointer() const
        {
            assert(!Empty());
            return m_pBuffer;
        };

    private:
        pointer m_pBuffer{};
        size_type m_Size{};
    };

}