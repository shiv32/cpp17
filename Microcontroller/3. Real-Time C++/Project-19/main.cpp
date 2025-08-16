#include <iostream>

class base
{
public:
    virtual ~base() {}
    base &operator=(const base &) = default;

protected:
    base() {}
};

class derived final : public base
{
public:
    derived() {}
    virtual ~derived() {}
    derived &operator=(const derived &) = default;
};

// class derived_another : public derived
// {
//     // This class should result in an error.
// };

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    return 0;
}
