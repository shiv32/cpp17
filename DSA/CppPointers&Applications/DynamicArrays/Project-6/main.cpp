#include <iostream>

class Integer
{
    int *m_ptr;

public:
    Integer()
    {
        std::clog << __PRETTY_FUNCTION__ << std::endl;
        m_ptr = nullptr;
    }

    Integer(const Integer &other)
    {
        std::clog << __PRETTY_FUNCTION__ << std::endl;
        m_ptr = new int(*other.m_ptr);
    }

    Integer &operator=(const Integer &other)
    {
        std::clog << __PRETTY_FUNCTION__ << std::endl;

        if (this != &other) // self-assignment check
        {
            delete m_ptr;                  // free existing resource
            m_ptr = new int(*other.m_ptr); // allocate new resource
        }

        return *this;
    }

    Integer(int value) : m_ptr(new int(value))
    {
        std::clog << __PRETTY_FUNCTION__ << std::endl;
    }

    ~Integer()
    {
        std::clog << __PRETTY_FUNCTION__ << std::endl;
        delete m_ptr;
    }
};

Integer Create(int x)
{
    Integer val{x};
    return val; // This will invoke the copy constructor
}
int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Integer val{5};
    // Integer val2 = val; // This will invoke the copy constructor, l-value

    // val2 = val; // This will invoke the copy assignment operator

    //  Integer val3 = Create(10); // This will invoke the copy constructor, r-value

    Integer val3;
    val3 = Create(10); // This will invoke the copy assignment operator

    return 0;
}