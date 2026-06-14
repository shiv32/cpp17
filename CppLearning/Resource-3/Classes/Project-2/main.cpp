#include <iostream>

namespace example1
{
    // C style

    struct Date // representation
    {
        int d, m, y;
    };

    void init_date(Date &d, int, int, int); // initialize d
    void add_year(Date &d, int n);          // add n years to d
    void add_month(Date &d, int n);         // add n months to d
    void add_day(Date &d, int n);           // add n days to d
}

namespace example2
{
    // C++ Style

    struct Date // representation
    {
        int d, m, y;

        void init(int dd, int mm, int yy); // initialize
        void add_year(int n);              // add n years
        void add_month(int n);             // add n months
        void add_day(int n);               // add n days
    };

    void Date::init(int dd, int mm, int yy)
    {
        d = dd;
        m = mm;
        y = yy;
    }

    void Date::add_day(int n)
    {
        d = d + n;
    }

    Date my_birthday;

    void f()
    {
        Date today;

        today.init(16, 10, 1996);
        my_birthday.init(30, 12, 1950);

        Date tomorrow = today;
        tomorrow.add_day(1);
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    return 0;
}