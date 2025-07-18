
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
        GArray(size_type count, const_reference elem) {};
        GArray(std::initializer_list<value_type> list) {};

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