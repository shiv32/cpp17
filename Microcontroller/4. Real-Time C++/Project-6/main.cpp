#include <iostream>

//led_base class and its derived classes are non-copyable.
class led_base
{
public:
private:
    // Private non-implemented copy constructor.
    led_base(const led_base &) = delete;

    // Private non-implemented copy assignment operator.
    const led_base &operator=(const led_base &) = delete;
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    return 0;
}
