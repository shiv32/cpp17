#include <iostream>

class Demo
{
public:
    Demo(std::string name) : mName(name)
    {
        std::clog << __PRETTY_FUNCTION__ << std::endl;
    }

    ~Demo()
    {
        std::clog << __PRETTY_FUNCTION__ << std::endl;
    }

    std::string getName() const
    {
        return mName;
    }

private:
    std::string mName{};
};

int main()
{
    // Basic -------------------------------------------------
    // int *p = new int(); // 4 b
    int *p = new int(7); // 4 b

    int *p2 = new int[5]{}; // 4 X 5 = 20 b

    //*p = 5;

    std::clog << *p << std::endl;

    for (size_t i = 0; i < 5; ++i)
    {
        *(p2 + i) = i * 10; // p2[i] = i*10;
    }

    for (size_t i = 0; i < 5; ++i)
    {
        std::clog << *(p2 + i) << ", "; // std::clog<<p2[i]<<", ";
    }

    std::clog << std::endl;

    delete p;
    p = nullptr;

    delete[] p2;
    p2 = nullptr;
    //-----------------------------------------------------------

    // user defined ---------------------------------------------
    Demo *d = new Demo("obj1");
    std::clog << d->getName() << std::endl;

    // Create array of Demo objects with default names
    Demo *d2 = new Demo[5]{Demo("obj2"), Demo("obj3"), Demo("obj4"), Demo("obj5"), Demo("obj6")};

    // Print names of all Demo objects in the array
    for (size_t i = 0; i < 5; ++i)
    {
        std::clog << (*(d2 + i)).getName() << ", ";
        // std::clog << (d2 + i)->getName() << ", ";
        // std::clog << d2[i].getName() << ", ";
    }

    std::clog << std::endl;

    delete d;
    d = nullptr;

    delete[] d2; // Clean up the array
    d2 = nullptr;
    //----------------------------------------------------------
}
