#include <iostream>
#include <sstream>
#include <algorithm>

template <typename T>
class dynamic_array
{
    T *data;
    size_t n;

public:
    dynamic_array(int n)
    {
        this->n = n;
        data = new T[n];
    }

    dynamic_array(const dynamic_array<T> &other)
    {
        n = other.n;
        data = new T[n];

        for (int i = 0; i < n; i++)
            data[i] = other[i];
    }

    T &operator[](int index)
    {
        return data[index];
    }

    const T &operator[](int index) const
    {
        return data[index];
    }

    T &at(int index)
    {
        if (index < n)
            return data[index];
        throw "Index out of range";
    }

    size_t size() const
    {
        return n;
    }

    ~dynamic_array()
    {
        delete[] data; // A destructor to prevent memory leak
    }

    T *begin()
    {
        return data;
    }

    const T *begin() const
    {
        return data;
    }

    T *end()
    {
        return data + n;
    }
    const T *end() const
    {
        return data + n;
    }

    friend dynamic_array<T> operator+(const dynamic_array<T> &arr1, dynamic_array<T> &arr2)
    {
        dynamic_array<T> result(arr1.size() + arr2.size());
        std::copy(arr1.begin(), arr1.end(), result.begin());
        std::copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());

        return result;
    }

    std::string to_string(const std::string &sep = ", ")
    {
        if (n == 0)
            return "";
        std::ostringstream os;
        os << data[0];

        for (int i = 1; i < n; i++)
            os << sep << data[i];

        return os.str();
    }
};

struct student
{
    std::string name;
    int standard;
};

std::ostream &operator<<(std::ostream &os, const student &s)
{
    return (os << "[Name: " << s.name << ", Standard: " << s.standard << "]");
}

int main()
{
     system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    int nStudents{1};
   
    dynamic_array<student> class1(nStudents);
  
    auto class2 = class1; // Deep copy

    std::cout << "Second class after initialized using first array : " << class2.to_string() << std::endl;

    auto class3 = class1 + class2;
    // Combines both classes and creates a bigger one

    std::cout << "Combined class : ";
    std::cout << class3.to_string() << std::endl;

    return 0;
}