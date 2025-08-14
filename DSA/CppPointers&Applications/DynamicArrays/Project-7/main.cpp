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

    Integer(Integer &&other)
    {
        std::clog << __PRETTY_FUNCTION__ << std::endl;
        m_ptr = other.m_ptr;
        other.m_ptr = nullptr;
    }

    Integer &operator=(Integer &&other)
    {
        std::clog << __PRETTY_FUNCTION__ << std::endl;

        if (this != &other) // self-assignment check
        {
            delete m_ptr; // free existing resource
            m_ptr = other.m_ptr;
            other.m_ptr = nullptr;
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

    // Integer val = Create(3);   //R value

    Integer val;
    //val = Create(3);

    // Integer val2 = val; // L value
    Integer val2 = std::move(val); // cast L value to R value

    return 0;
}