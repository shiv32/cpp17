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
        ~GArray() {};

        void Add(const_reference elem) {};
        void Insert(size_type index, const_reference elem) {};
        void Erase(size_type index) {};
        const_reference Back() const {};
        const_reference Front() const {};
        const_reference operator[](size_type index) const {};
        reference operator[](size_type index) {};
        const_reference GetAt(size_type index) const {};
        reference GetAt(size_type index) {};
        bool Empty() const {};
        size_type GetSize() const {};
        void Clear() {};
        size_type Find(const_reference elem) {};
        pointer GetRawPointer() {};
        const_pointer GetRawPointer() const {};

    private:
        pointer m_pBuffer{};
        size_type m_Size{};
    };

}