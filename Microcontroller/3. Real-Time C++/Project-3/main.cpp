#include <iostream>

bool valid();
bool login();
void start_session();
void do_something();

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    do_something();

    return 0;
}

bool valid()
{
    std::clog << __PRETTY_FUNCTION__ << std::endl;

    return true;
}

bool login()
{
    std::clog << __PRETTY_FUNCTION__ << std::endl;

    return true;
}

void start_session()
{
    std::clog << __PRETTY_FUNCTION__ << std::endl;
}

void do_something()
{
    // This Boolean test yields true or false.
    const bool session_is_ok = (valid() && login());

    // This tests if (session_is_ok == true).
    if (session_is_ok)
    {
        start_session();
    }
}