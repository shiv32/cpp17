#include <iostream>
#include <memory>

class Base
{
public:
    virtual ~Base()
    //~Base()
    {
        std::clog << __PRETTY_FUNCTION__ << std::endl;
    }
};

class Derived final : public Base
{
public:
    Derived() = default;

    ~Derived()
    {
        std::clog << __PRETTY_FUNCTION__ << std::endl;
    }
};

int main()
{
    // Base *base = new Derived();
    // delete base;
    // base = nullptr;

    // or
    std::unique_ptr<Base> base = std::make_unique<Derived>();
}
