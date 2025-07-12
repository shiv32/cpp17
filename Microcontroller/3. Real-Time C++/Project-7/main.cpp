#include <iostream>
#include <memory>

class something
{
  public:
    something() { }
};

namespace
{
    // Default initialized to nullptr (i.e., 0).
    something *ps;

    // not nullptr
    //auto ps = std::make_unique<something>();
}

void do_something()
{
    // Any kind of zero pointer equals nullptr.
    if (ps == nullptr)
    {
        // Initialize ps.
        std::clog << "ps is null !" << std::endl;
        return;
    }
    // Do something with ps.
    std::clog << "ps is not null !" << std::endl;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    do_something();
    return 0;
}
